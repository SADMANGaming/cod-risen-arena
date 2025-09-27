const fs = require('fs');
const path = require('path');

const inputFile = path.join(__dirname, 'functions.txt');
const outputFile = path.join(__dirname, 'mss32_proxy.cpp');

const functions = fs.readFileSync(inputFile, 'utf-8')
  .split(/\r?\n/)
  .map(line => line.trim())
  .filter(line => line.length > 0);

function cleanNameForPtr(name) {
  return name.replace(/^_+/, ''); // remove leading underscores only for ptr name
}

let content = `// Auto-generated proxy (MinGW/GCC naked jump style)\n`;
content += `#include <windows.h>\n\n`;
content += `HMODULE hRealMSS32 = NULL;\n\n`;

// Declare FARPROC pointers
functions.forEach(fn => {
  const match = fn.match(/(.+)@(\d+)/);
  const name = match ? match[1] : fn;
  const clean = cleanNameForPtr(name);
  content += `FARPROC p${clean} = NULL;\n`;
});
content += `\n`;

// Loader that fills pointers
content += `void loadRealMSS32() {\n`;
content += `    if (hRealMSS32) return;\n`;
content += `    hRealMSS32 = LoadLibraryA("mss32.dll");\n`;
content += `    if (!hRealMSS32) {\n`;
content += `        MessageBoxA(NULL, "Cannot load real mss32.dll!", "Proxy Error", MB_OK | MB_ICONERROR);\n`;
content += `        return;\n`;
content += `    }\n\n`;

functions.forEach(fn => {
  const match = fn.match(/(.+)@(\d+)/);
  const name = match ? match[1] : fn;
  const clean = cleanNameForPtr(name);
  content += `    p${clean} = GetProcAddress(hRealMSS32, "${name}");\n`;
});
content += `}\n\n`;

// Generate exported naked proxies with parameter lists
functions.forEach(fn => {
  const match = fn.match(/(.+)@(\d+)/);
  const name = match ? match[1] : fn;
  const stack = match ? parseInt(match[2], 10) : 0;
  const paramCount = stack ? Math.max(0, stack / 4) : 0;

  // build params like "DWORD a0, DWORD a1"
  const params = [];
  for (let i = 0; i < paramCount; ++i) params.push(`DWORD a${i}`);
  const paramsStr = params.join(', ');

  const clean = cleanNameForPtr(name);
  // Exported symbol must match original name (keep underscores). Use the original 'name' in asm export.
  // We'll emit function with that export name by declaring with the exact name.
  content += `extern "C" __declspec(dllexport) __attribute__((naked)) void ${name}(${paramsStr}) {\n`;
  content += `    // ensure pointers are initialized (cheap check)\n`;
  content += `    if (!p${clean}) loadRealMSS32();\n`;
  content += `    __asm__ volatile (\n`;
  content += `        \"jmp *%0\"\n`;
  content += `        :\n`;
  content += `        : \"r\"(p${clean})\n`;
  content += `    );\n`;
  content += `}\n\n`;
});

fs.writeFileSync(outputFile, content, 'utf8');
console.log(`Generated ${functions.length} proxy functions in ${outputFile}`);
