// Auto-generated proxy (MinGW/GCC naked jump style)
#include <windows.h>
#include "mss32.hpp"

HMODULE hMSS = NULL;

FARPROC pAIL_debug_printf = NULL;
FARPROC pAIL_sprintf = NULL;
FARPROC pDLSClose = NULL;
FARPROC pDLSCompactMemory = NULL;
FARPROC pDLSGetInfo = NULL;
FARPROC pDLSLoadFile = NULL;
FARPROC pDLSLoadMemFile = NULL;
FARPROC pDLSMSSOpen = NULL;
FARPROC pDLSSetAttribute = NULL;
FARPROC pDLSUnloadAll = NULL;
FARPROC pDLSUnloadFile = NULL;
FARPROC pRIB_alloc_provider_handle = NULL;
FARPROC pRIB_enumerate_interface = NULL;
FARPROC pRIB_error = NULL;
FARPROC pRIB_find_file_provider = NULL;
FARPROC pRIB_free_provider_handle = NULL;
FARPROC pRIB_free_provider_library = NULL;
FARPROC pRIB_load_provider_library = NULL;
FARPROC pRIB_register_interface = NULL;
FARPROC pRIB_request_interface = NULL;
FARPROC pRIB_request_interface_entry = NULL;
FARPROC pRIB_type_string = NULL;
FARPROC pRIB_unregister_interface = NULL;
FARPROC pAIL_3D_distance_factor = NULL;
FARPROC pAIL_3D_doppler_factor = NULL;
FARPROC pAIL_3D_orientation = NULL;
FARPROC pAIL_3D_position = NULL;
FARPROC pAIL_3D_provider_attribute = NULL;
FARPROC pAIL_3D_rolloff_factor = NULL;
FARPROC pAIL_3D_room_type = NULL;
FARPROC pAIL_3D_sample_attribute = NULL;
FARPROC pAIL_3D_sample_cone = NULL;
FARPROC pAIL_3D_sample_distances = NULL;
FARPROC pAIL_3D_sample_effects_level = NULL;
FARPROC pAIL_3D_sample_exclusion = NULL;
FARPROC pAIL_3D_sample_length = NULL;
FARPROC pAIL_3D_sample_loop_count = NULL;
FARPROC pAIL_3D_sample_obstruction = NULL;
FARPROC pAIL_3D_sample_occlusion = NULL;
FARPROC pAIL_3D_sample_offset = NULL;
FARPROC pAIL_3D_sample_playback_rate = NULL;
FARPROC pAIL_3D_sample_status = NULL;
FARPROC pAIL_3D_sample_volume = NULL;
FARPROC pAIL_3D_speaker_type = NULL;
FARPROC pAIL_3D_user_data = NULL;
FARPROC pAIL_3D_velocity = NULL;
FARPROC pAIL_DLS_close = NULL;
FARPROC pAIL_DLS_compact = NULL;
FARPROC pAIL_DLS_get_info = NULL;
FARPROC pAIL_DLS_get_reverb_levels = NULL;
FARPROC pAIL_DLS_load_file = NULL;
FARPROC pAIL_DLS_load_memory = NULL;
FARPROC pAIL_DLS_open = NULL;
FARPROC pAIL_DLS_set_reverb_levels = NULL;
FARPROC pAIL_DLS_unload = NULL;
FARPROC pAIL_HWND = NULL;
FARPROC pAIL_MIDI_handle_reacquire = NULL;
FARPROC pAIL_MIDI_handle_release = NULL;
FARPROC pAIL_MIDI_to_XMI = NULL;
FARPROC pAIL_MMX_available = NULL;
FARPROC pAIL_WAV_file_write = NULL;
FARPROC pAIL_WAV_info = NULL;
FARPROC pAIL_XMIDI_master_volume = NULL;
FARPROC pAIL_active_3D_sample_count = NULL;
FARPROC pAIL_active_sample_count = NULL;
FARPROC pAIL_active_sequence_count = NULL;
FARPROC pAIL_allocate_3D_sample_handle = NULL;
FARPROC pAIL_allocate_file_sample = NULL;
FARPROC pAIL_allocate_sample_handle = NULL;
FARPROC pAIL_allocate_sequence_handle = NULL;
FARPROC pAIL_auto_service_stream = NULL;
FARPROC pAIL_auto_update_3D_position = NULL;
FARPROC pAIL_background = NULL;
FARPROC pAIL_branch_index = NULL;
FARPROC pAIL_channel_notes = NULL;
FARPROC pAIL_close_3D_listener = NULL;
FARPROC pAIL_close_3D_object = NULL;
FARPROC pAIL_close_3D_provider = NULL;
FARPROC pAIL_close_XMIDI_driver = NULL;
FARPROC pAIL_close_digital_driver = NULL;
FARPROC pAIL_close_filter = NULL;
FARPROC pAIL_close_input = NULL;
FARPROC pAIL_close_stream = NULL;
FARPROC pAIL_compress_ADPCM = NULL;
FARPROC pAIL_compress_ASI = NULL;
FARPROC pAIL_compress_DLS = NULL;
FARPROC pAIL_controller_value = NULL;
FARPROC pAIL_create_wave_synthesizer = NULL;
FARPROC pAIL_decompress_ADPCM = NULL;
FARPROC pAIL_decompress_ASI = NULL;
FARPROC pAIL_delay = NULL;
FARPROC pAIL_destroy_wave_synthesizer = NULL;
FARPROC pAIL_digital_CPU_percent = NULL;
FARPROC pAIL_digital_configuration = NULL;
FARPROC pAIL_digital_handle_reacquire = NULL;
FARPROC pAIL_digital_handle_release = NULL;
FARPROC pAIL_digital_latency = NULL;
FARPROC pAIL_digital_master_reverb = NULL;
FARPROC pAIL_digital_master_reverb_levels = NULL;
FARPROC pAIL_digital_master_volume_level = NULL;
FARPROC pAIL_end_3D_sample = NULL;
FARPROC pAIL_end_sample = NULL;
FARPROC pAIL_end_sequence = NULL;
FARPROC pAIL_enumerate_3D_provider_attributes = NULL;
FARPROC pAIL_enumerate_3D_providers = NULL;
FARPROC pAIL_enumerate_3D_sample_attributes = NULL;
FARPROC pAIL_enumerate_filter_attributes = NULL;
FARPROC pAIL_enumerate_filter_sample_attributes = NULL;
FARPROC pAIL_enumerate_filters = NULL;
FARPROC pAIL_extract_DLS = NULL;
FARPROC pAIL_file_error = NULL;
FARPROC pAIL_file_read = NULL;
FARPROC pAIL_file_size = NULL;
FARPROC pAIL_file_type = NULL;
FARPROC pAIL_file_write = NULL;
FARPROC pAIL_filter_DLS_attribute = NULL;
FARPROC pAIL_filter_DLS_with_XMI = NULL;
FARPROC pAIL_filter_attribute = NULL;
FARPROC pAIL_filter_sample_attribute = NULL;
FARPROC pAIL_filter_stream_attribute = NULL;
FARPROC pAIL_find_DLS = NULL;
FARPROC pAIL_get_DirectSound_info = NULL;
FARPROC pAIL_get_input_info = NULL;
FARPROC pAIL_get_preference = NULL;
FARPROC pAIL_get_timer_highest_delay = NULL;
FARPROC pAIL_init_sample = NULL;
FARPROC pAIL_init_sequence = NULL;
FARPROC pAIL_last_error = NULL;
FARPROC pAIL_list_DLS = NULL;
FARPROC pAIL_list_MIDI = NULL;
FARPROC pAIL_load_sample_buffer = NULL;
FARPROC pAIL_lock = NULL;
FARPROC pAIL_lock_channel = NULL;
FARPROC pAIL_lock_mutex = NULL;
FARPROC pAIL_map_sequence_channel = NULL;
FARPROC pAIL_mem_alloc_lock = NULL;
FARPROC pAIL_mem_free_lock = NULL;
FARPROC pAIL_mem_use_free = NULL;
FARPROC pAIL_mem_use_malloc = NULL;
FARPROC pAIL_merge_DLS_with_XMI = NULL;
FARPROC pAIL_midiOutClose = NULL;
FARPROC pAIL_midiOutOpen = NULL;
FARPROC pAIL_minimum_sample_buffer_size = NULL;
FARPROC pAIL_ms_count = NULL;
FARPROC pAIL_open_3D_listener = NULL;
FARPROC pAIL_open_3D_object = NULL;
FARPROC pAIL_open_3D_provider = NULL;
FARPROC pAIL_open_XMIDI_driver = NULL;
FARPROC pAIL_open_digital_driver = NULL;
FARPROC pAIL_open_filter = NULL;
FARPROC pAIL_open_input = NULL;
FARPROC pAIL_open_stream = NULL;
FARPROC pAIL_pause_stream = NULL;
FARPROC pAIL_primary_digital_driver = NULL;
FARPROC pAIL_process_digital_audio = NULL;
FARPROC pAIL_quick_copy = NULL;
FARPROC pAIL_quick_halt = NULL;
FARPROC pAIL_quick_handles = NULL;
FARPROC pAIL_quick_load = NULL;
FARPROC pAIL_quick_load_and_play = NULL;
FARPROC pAIL_quick_load_mem = NULL;
FARPROC pAIL_quick_ms_length = NULL;
FARPROC pAIL_quick_ms_position = NULL;
FARPROC pAIL_quick_play = NULL;
FARPROC pAIL_quick_set_low_pass_cut_off = NULL;
FARPROC pAIL_quick_set_ms_position = NULL;
FARPROC pAIL_quick_set_reverb_levels = NULL;
FARPROC pAIL_quick_set_speed = NULL;
FARPROC pAIL_quick_set_volume = NULL;
FARPROC pAIL_quick_shutdown = NULL;
FARPROC pAIL_quick_startup = NULL;
FARPROC pAIL_quick_status = NULL;
FARPROC pAIL_quick_type = NULL;
FARPROC pAIL_quick_unload = NULL;
FARPROC pAIL_redbook_close = NULL;
FARPROC pAIL_redbook_eject = NULL;
FARPROC pAIL_redbook_id = NULL;
FARPROC pAIL_redbook_open = NULL;
FARPROC pAIL_redbook_open_drive = NULL;
FARPROC pAIL_redbook_pause = NULL;
FARPROC pAIL_redbook_play = NULL;
FARPROC pAIL_redbook_position = NULL;
FARPROC pAIL_redbook_resume = NULL;
FARPROC pAIL_redbook_retract = NULL;
FARPROC pAIL_redbook_set_volume_level = NULL;
FARPROC pAIL_redbook_status = NULL;
FARPROC pAIL_redbook_stop = NULL;
FARPROC pAIL_redbook_track = NULL;
FARPROC pAIL_redbook_track_info = NULL;
FARPROC pAIL_redbook_tracks = NULL;
FARPROC pAIL_redbook_volume_level = NULL;
FARPROC pAIL_register_3D_EOS_callback = NULL;
FARPROC pAIL_register_EOB_callback = NULL;
FARPROC pAIL_register_EOF_callback = NULL;
FARPROC pAIL_register_EOS_callback = NULL;
FARPROC pAIL_register_ICA_array = NULL;
FARPROC pAIL_register_SOB_callback = NULL;
FARPROC pAIL_register_beat_callback = NULL;
FARPROC pAIL_register_event_callback = NULL;
FARPROC pAIL_register_prefix_callback = NULL;
FARPROC pAIL_register_sequence_callback = NULL;
FARPROC pAIL_register_stream_callback = NULL;
FARPROC pAIL_register_timbre_callback = NULL;
FARPROC pAIL_register_timer = NULL;
FARPROC pAIL_register_trigger_callback = NULL;
FARPROC pAIL_release_3D_sample_handle = NULL;
FARPROC pAIL_release_all_timers = NULL;
FARPROC pAIL_release_channel = NULL;
FARPROC pAIL_release_sample_handle = NULL;
FARPROC pAIL_release_sequence_handle = NULL;
FARPROC pAIL_release_timer_handle = NULL;
FARPROC pAIL_request_EOB_ASI_reset = NULL;
FARPROC pAIL_resume_3D_sample = NULL;
FARPROC pAIL_resume_sample = NULL;
FARPROC pAIL_resume_sequence = NULL;
FARPROC pAIL_sample_buffer_info = NULL;
FARPROC pAIL_sample_buffer_ready = NULL;
FARPROC pAIL_sample_granularity = NULL;
FARPROC pAIL_sample_loop_count = NULL;
FARPROC pAIL_sample_low_pass_cut_off = NULL;
FARPROC pAIL_sample_ms_position = NULL;
FARPROC pAIL_sample_playback_rate = NULL;
FARPROC pAIL_sample_position = NULL;
FARPROC pAIL_sample_reverb_levels = NULL;
FARPROC pAIL_sample_status = NULL;
FARPROC pAIL_sample_user_data = NULL;
FARPROC pAIL_sample_volume_levels = NULL;
FARPROC pAIL_sample_volume_pan = NULL;
FARPROC pAIL_send_channel_voice_message = NULL;
FARPROC pAIL_send_sysex_message = NULL;
FARPROC pAIL_sequence_loop_count = NULL;
FARPROC pAIL_sequence_ms_position = NULL;
FARPROC pAIL_sequence_position = NULL;
FARPROC pAIL_sequence_status = NULL;
FARPROC pAIL_sequence_tempo = NULL;
FARPROC pAIL_sequence_user_data = NULL;
FARPROC pAIL_sequence_volume = NULL;
FARPROC pAIL_serve = NULL;
FARPROC pAIL_service_stream = NULL;
FARPROC pAIL_set_3D_distance_factor = NULL;
FARPROC pAIL_set_3D_doppler_factor = NULL;
FARPROC pAIL_set_3D_orientation = NULL;
FARPROC pAIL_set_3D_position = NULL;
FARPROC pAIL_set_3D_provider_preference = NULL;
FARPROC pAIL_set_3D_rolloff_factor = NULL;
FARPROC pAIL_set_3D_room_type = NULL;
FARPROC pAIL_set_3D_sample_cone = NULL;
FARPROC pAIL_set_3D_sample_distances = NULL;
FARPROC pAIL_set_3D_sample_effects_level = NULL;
FARPROC pAIL_set_3D_sample_exclusion = NULL;
FARPROC pAIL_set_3D_sample_file = NULL;
FARPROC pAIL_set_3D_sample_info = NULL;
FARPROC pAIL_set_3D_sample_loop_block = NULL;
FARPROC pAIL_set_3D_sample_loop_count = NULL;
FARPROC pAIL_set_3D_sample_obstruction = NULL;
FARPROC pAIL_set_3D_sample_occlusion = NULL;
FARPROC pAIL_set_3D_sample_offset = NULL;
FARPROC pAIL_set_3D_sample_playback_rate = NULL;
FARPROC pAIL_set_3D_sample_preference = NULL;
FARPROC pAIL_set_3D_sample_volume = NULL;
FARPROC pAIL_set_3D_speaker_type = NULL;
FARPROC pAIL_set_3D_user_data = NULL;
FARPROC pAIL_set_3D_velocity = NULL;
FARPROC pAIL_set_3D_velocity_vector = NULL;
FARPROC pAIL_set_DLS_processor = NULL;
FARPROC pAIL_set_DirectSound_HWND = NULL;
FARPROC pAIL_set_XMIDI_master_volume = NULL;
FARPROC pAIL_set_digital_driver_processor = NULL;
FARPROC pAIL_set_digital_master_reverb = NULL;
FARPROC pAIL_set_digital_master_reverb_levels = NULL;
FARPROC pAIL_set_digital_master_room_type = NULL;
FARPROC pAIL_set_digital_master_volume_level = NULL;
FARPROC pAIL_set_error = NULL;
FARPROC pAIL_set_file_async_callbacks = NULL;
FARPROC pAIL_set_file_callbacks = NULL;
FARPROC pAIL_set_filter_DLS_preference = NULL;
FARPROC pAIL_set_filter_preference = NULL;
FARPROC pAIL_set_filter_sample_preference = NULL;
FARPROC pAIL_set_filter_stream_preference = NULL;
FARPROC pAIL_set_input_state = NULL;
FARPROC pAIL_set_named_sample_file = NULL;
FARPROC pAIL_set_preference = NULL;
FARPROC pAIL_set_redist_directory = NULL;
FARPROC pAIL_set_sample_address = NULL;
FARPROC pAIL_set_sample_adpcm_block_size = NULL;
FARPROC pAIL_set_sample_file = NULL;
FARPROC pAIL_set_sample_loop_block = NULL;
FARPROC pAIL_set_sample_loop_count = NULL;
FARPROC pAIL_set_sample_low_pass_cut_off = NULL;
FARPROC pAIL_set_sample_ms_position = NULL;
FARPROC pAIL_set_sample_playback_rate = NULL;
FARPROC pAIL_set_sample_position = NULL;
FARPROC pAIL_set_sample_processor = NULL;
FARPROC pAIL_set_sample_reverb_levels = NULL;
FARPROC pAIL_set_sample_type = NULL;
FARPROC pAIL_set_sample_user_data = NULL;
FARPROC pAIL_set_sample_volume_levels = NULL;
FARPROC pAIL_set_sample_volume_pan = NULL;
FARPROC pAIL_set_sequence_loop_count = NULL;
FARPROC pAIL_set_sequence_ms_position = NULL;
FARPROC pAIL_set_sequence_tempo = NULL;
FARPROC pAIL_set_sequence_user_data = NULL;
FARPROC pAIL_set_sequence_volume = NULL;
FARPROC pAIL_set_stream_loop_block = NULL;
FARPROC pAIL_set_stream_loop_count = NULL;
FARPROC pAIL_set_stream_low_pass_cut_off = NULL;
FARPROC pAIL_set_stream_ms_position = NULL;
FARPROC pAIL_set_stream_playback_rate = NULL;
FARPROC pAIL_set_stream_position = NULL;
FARPROC pAIL_set_stream_processor = NULL;
FARPROC pAIL_set_stream_reverb_levels = NULL;
FARPROC pAIL_set_stream_user_data = NULL;
FARPROC pAIL_set_stream_volume_levels = NULL;
FARPROC pAIL_set_stream_volume_pan = NULL;
FARPROC pAIL_set_timer_divisor = NULL;
FARPROC pAIL_set_timer_frequency = NULL;
FARPROC pAIL_set_timer_period = NULL;
FARPROC pAIL_set_timer_user = NULL;
FARPROC pAIL_shutdown = NULL;
FARPROC pAIL_size_processed_digital_audio = NULL;
FARPROC pAIL_start_3D_sample = NULL;
FARPROC pAIL_start_all_timers = NULL;
FARPROC pAIL_start_sample = NULL;
FARPROC pAIL_start_sequence = NULL;
FARPROC pAIL_start_stream = NULL;
FARPROC pAIL_start_timer = NULL;
FARPROC pAIL_startup = NULL;
FARPROC pAIL_stop_3D_sample = NULL;
FARPROC pAIL_stop_all_timers = NULL;
FARPROC pAIL_stop_sample = NULL;
FARPROC pAIL_stop_sequence = NULL;
FARPROC pAIL_stop_timer = NULL;
FARPROC pAIL_stream_info = NULL;
FARPROC pAIL_stream_loop_count = NULL;
FARPROC pAIL_stream_low_pass_cut_off = NULL;
FARPROC pAIL_stream_ms_position = NULL;
FARPROC pAIL_stream_playback_rate = NULL;
FARPROC pAIL_stream_position = NULL;
FARPROC pAIL_stream_reverb_levels = NULL;
FARPROC pAIL_stream_status = NULL;
FARPROC pAIL_stream_user_data = NULL;
FARPROC pAIL_stream_volume_levels = NULL;
FARPROC pAIL_stream_volume_pan = NULL;
FARPROC pAIL_true_sequence_channel = NULL;
FARPROC pAIL_unlock = NULL;
FARPROC pAIL_unlock_mutex = NULL;
FARPROC pAIL_update_3D_position = NULL;
FARPROC pAIL_us_count = NULL;
FARPROC pAIL_waveOutClose = NULL;
FARPROC pAIL_waveOutOpen = NULL;
FARPROC pDLSMSSGetCPU = NULL;
FARPROC pMIX_RIB_MAIN = NULL;
FARPROC pRIB_enumerate_providers = NULL;
FARPROC pRIB_find_file_dec_provider = NULL;
FARPROC pRIB_find_files_provider = NULL;
FARPROC pRIB_find_provider = NULL;
FARPROC pRIB_load_application_providers = NULL;
FARPROC pRIB_load_static_provider_library = NULL;
FARPROC pRIB_provider_system_data = NULL;
FARPROC pRIB_provider_user_data = NULL;
FARPROC pRIB_set_provider_system_data = NULL;
FARPROC pRIB_set_provider_user_data = NULL;
FARPROC pstream_background = NULL;
static void(*Com_Quit_f)() = (void(*)())0x435D80;

extern "C" void MSS32_Unload() {
	if (hMSS != nullptr)
		FreeLibrary(hMSS);
	//MsgBox("mss32 unloaded");
}


bool miles32_loaded = false;
void loadRealMSS32() {
    if (hMSS) return;
    hMSS = LoadLibraryA("miles32.dll");
    if (!hMSS) {
        MessageBoxA(NULL, "Cannot load real miles32.dll!", "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
        Com_Quit_f();
        return;
    }
/*Fuck this shits down here
    pAIL_debug_printf = GetProcAddress(hRealMSS32, "AIL_debug_printf");
    pAIL_sprintf = GetProcAddress(hRealMSS32, "AIL_sprintf");
    pDLSClose = GetProcAddress(hRealMSS32, "DLSClose");
    pDLSCompactMemory = GetProcAddress(hRealMSS32, "DLSCompactMemory");
    pDLSGetInfo = GetProcAddress(hRealMSS32, "DLSGetInfo");
    pDLSLoadFile = GetProcAddress(hRealMSS32, "DLSLoadFile");
    pDLSLoadMemFile = GetProcAddress(hRealMSS32, "DLSLoadMemFile");
    pDLSMSSOpen = GetProcAddress(hRealMSS32, "DLSMSSOpen");
    pDLSSetAttribute = GetProcAddress(hRealMSS32, "DLSSetAttribute");
    pDLSUnloadAll = GetProcAddress(hRealMSS32, "DLSUnloadAll");
    pDLSUnloadFile = GetProcAddress(hRealMSS32, "DLSUnloadFile");
    pRIB_alloc_provider_handle = GetProcAddress(hRealMSS32, "RIB_alloc_provider_handle");
    pRIB_enumerate_interface = GetProcAddress(hRealMSS32, "RIB_enumerate_interface");
    pRIB_error = GetProcAddress(hRealMSS32, "RIB_error");
    pRIB_find_file_provider = GetProcAddress(hRealMSS32, "RIB_find_file_provider");
    pRIB_free_provider_handle = GetProcAddress(hRealMSS32, "RIB_free_provider_handle");
    pRIB_free_provider_library = GetProcAddress(hRealMSS32, "RIB_free_provider_library");
    pRIB_load_provider_library = GetProcAddress(hRealMSS32, "RIB_load_provider_library");
    pRIB_register_interface = GetProcAddress(hRealMSS32, "RIB_register_interface");
    pRIB_request_interface = GetProcAddress(hRealMSS32, "RIB_request_interface");
    pRIB_request_interface_entry = GetProcAddress(hRealMSS32, "RIB_request_interface_entry");
    pRIB_type_string = GetProcAddress(hRealMSS32, "RIB_type_string");
    pRIB_unregister_interface = GetProcAddress(hRealMSS32, "RIB_unregister_interface");
    pAIL_3D_distance_factor = GetProcAddress(hRealMSS32, "_AIL_3D_distance_factor");
    pAIL_3D_doppler_factor = GetProcAddress(hRealMSS32, "_AIL_3D_doppler_factor");
    pAIL_3D_orientation = GetProcAddress(hRealMSS32, "_AIL_3D_orientation");
    pAIL_3D_position = GetProcAddress(hRealMSS32, "_AIL_3D_position");
    pAIL_3D_provider_attribute = GetProcAddress(hRealMSS32, "_AIL_3D_provider_attribute");
    pAIL_3D_rolloff_factor = GetProcAddress(hRealMSS32, "_AIL_3D_rolloff_factor");
    pAIL_3D_room_type = GetProcAddress(hRealMSS32, "_AIL_3D_room_type");
    pAIL_3D_sample_attribute = GetProcAddress(hRealMSS32, "_AIL_3D_sample_attribute");
    pAIL_3D_sample_cone = GetProcAddress(hRealMSS32, "_AIL_3D_sample_cone");
    pAIL_3D_sample_distances = GetProcAddress(hRealMSS32, "_AIL_3D_sample_distances");
    pAIL_3D_sample_effects_level = GetProcAddress(hRealMSS32, "_AIL_3D_sample_effects_level");
    pAIL_3D_sample_exclusion = GetProcAddress(hRealMSS32, "_AIL_3D_sample_exclusion");
    pAIL_3D_sample_length = GetProcAddress(hRealMSS32, "_AIL_3D_sample_length");
    pAIL_3D_sample_loop_count = GetProcAddress(hRealMSS32, "_AIL_3D_sample_loop_count");
    pAIL_3D_sample_obstruction = GetProcAddress(hRealMSS32, "_AIL_3D_sample_obstruction");
    pAIL_3D_sample_occlusion = GetProcAddress(hRealMSS32, "_AIL_3D_sample_occlusion");
    pAIL_3D_sample_offset = GetProcAddress(hRealMSS32, "_AIL_3D_sample_offset");
    pAIL_3D_sample_playback_rate = GetProcAddress(hRealMSS32, "_AIL_3D_sample_playback_rate");
    pAIL_3D_sample_status = GetProcAddress(hRealMSS32, "_AIL_3D_sample_status");
    pAIL_3D_sample_volume = GetProcAddress(hRealMSS32, "_AIL_3D_sample_volume");
    pAIL_3D_speaker_type = GetProcAddress(hRealMSS32, "_AIL_3D_speaker_type");
    pAIL_3D_user_data = GetProcAddress(hRealMSS32, "_AIL_3D_user_data");
    pAIL_3D_velocity = GetProcAddress(hRealMSS32, "_AIL_3D_velocity");
    pAIL_DLS_close = GetProcAddress(hRealMSS32, "_AIL_DLS_close");
    pAIL_DLS_compact = GetProcAddress(hRealMSS32, "_AIL_DLS_compact");
    pAIL_DLS_get_info = GetProcAddress(hRealMSS32, "_AIL_DLS_get_info");
    pAIL_DLS_get_reverb_levels = GetProcAddress(hRealMSS32, "_AIL_DLS_get_reverb_levels");
    pAIL_DLS_load_file = GetProcAddress(hRealMSS32, "_AIL_DLS_load_file");
    pAIL_DLS_load_memory = GetProcAddress(hRealMSS32, "_AIL_DLS_load_memory");
    pAIL_DLS_open = GetProcAddress(hRealMSS32, "_AIL_DLS_open");
    pAIL_DLS_set_reverb_levels = GetProcAddress(hRealMSS32, "_AIL_DLS_set_reverb_levels");
    pAIL_DLS_unload = GetProcAddress(hRealMSS32, "_AIL_DLS_unload");
    pAIL_HWND = GetProcAddress(hRealMSS32, "_AIL_HWND");
    pAIL_MIDI_handle_reacquire = GetProcAddress(hRealMSS32, "_AIL_MIDI_handle_reacquire");
    pAIL_MIDI_handle_release = GetProcAddress(hRealMSS32, "_AIL_MIDI_handle_release");
    pAIL_MIDI_to_XMI = GetProcAddress(hRealMSS32, "_AIL_MIDI_to_XMI");
    pAIL_MMX_available = GetProcAddress(hRealMSS32, "_AIL_MMX_available");
    pAIL_WAV_file_write = GetProcAddress(hRealMSS32, "_AIL_WAV_file_write");
    pAIL_WAV_info = GetProcAddress(hRealMSS32, "_AIL_WAV_info");
    pAIL_XMIDI_master_volume = GetProcAddress(hRealMSS32, "_AIL_XMIDI_master_volume");
    pAIL_active_3D_sample_count = GetProcAddress(hRealMSS32, "_AIL_active_3D_sample_count");
    pAIL_active_sample_count = GetProcAddress(hRealMSS32, "_AIL_active_sample_count");
    pAIL_active_sequence_count = GetProcAddress(hRealMSS32, "_AIL_active_sequence_count");
    pAIL_allocate_3D_sample_handle = GetProcAddress(hRealMSS32, "_AIL_allocate_3D_sample_handle");
    pAIL_allocate_file_sample = GetProcAddress(hRealMSS32, "_AIL_allocate_file_sample");
    pAIL_allocate_sample_handle = GetProcAddress(hRealMSS32, "_AIL_allocate_sample_handle");
    pAIL_allocate_sequence_handle = GetProcAddress(hRealMSS32, "_AIL_allocate_sequence_handle");
    pAIL_auto_service_stream = GetProcAddress(hRealMSS32, "_AIL_auto_service_stream");
    pAIL_auto_update_3D_position = GetProcAddress(hRealMSS32, "_AIL_auto_update_3D_position");
    pAIL_background = GetProcAddress(hRealMSS32, "_AIL_background");
    pAIL_branch_index = GetProcAddress(hRealMSS32, "_AIL_branch_index");
    pAIL_channel_notes = GetProcAddress(hRealMSS32, "_AIL_channel_notes");
    pAIL_close_3D_listener = GetProcAddress(hRealMSS32, "_AIL_close_3D_listener");
    pAIL_close_3D_object = GetProcAddress(hRealMSS32, "_AIL_close_3D_object");
    pAIL_close_3D_provider = GetProcAddress(hRealMSS32, "_AIL_close_3D_provider");
    pAIL_close_XMIDI_driver = GetProcAddress(hRealMSS32, "_AIL_close_XMIDI_driver");
    pAIL_close_digital_driver = GetProcAddress(hRealMSS32, "_AIL_close_digital_driver");
    pAIL_close_filter = GetProcAddress(hRealMSS32, "_AIL_close_filter");
    pAIL_close_input = GetProcAddress(hRealMSS32, "_AIL_close_input");
    pAIL_close_stream = GetProcAddress(hRealMSS32, "_AIL_close_stream");
    pAIL_compress_ADPCM = GetProcAddress(hRealMSS32, "_AIL_compress_ADPCM");
    pAIL_compress_ASI = GetProcAddress(hRealMSS32, "_AIL_compress_ASI");
    pAIL_compress_DLS = GetProcAddress(hRealMSS32, "_AIL_compress_DLS");
    pAIL_controller_value = GetProcAddress(hRealMSS32, "_AIL_controller_value");
    pAIL_create_wave_synthesizer = GetProcAddress(hRealMSS32, "_AIL_create_wave_synthesizer");
    pAIL_decompress_ADPCM = GetProcAddress(hRealMSS32, "_AIL_decompress_ADPCM");
    pAIL_decompress_ASI = GetProcAddress(hRealMSS32, "_AIL_decompress_ASI");
    pAIL_delay = GetProcAddress(hRealMSS32, "_AIL_delay");
    pAIL_destroy_wave_synthesizer = GetProcAddress(hRealMSS32, "_AIL_destroy_wave_synthesizer");
    pAIL_digital_CPU_percent = GetProcAddress(hRealMSS32, "_AIL_digital_CPU_percent");
    pAIL_digital_configuration = GetProcAddress(hRealMSS32, "_AIL_digital_configuration");
    pAIL_digital_handle_reacquire = GetProcAddress(hRealMSS32, "_AIL_digital_handle_reacquire");
    pAIL_digital_handle_release = GetProcAddress(hRealMSS32, "_AIL_digital_handle_release");
    pAIL_digital_latency = GetProcAddress(hRealMSS32, "_AIL_digital_latency");
    pAIL_digital_master_reverb = GetProcAddress(hRealMSS32, "_AIL_digital_master_reverb");
    pAIL_digital_master_reverb_levels = GetProcAddress(hRealMSS32, "_AIL_digital_master_reverb_levels");
    pAIL_digital_master_volume_level = GetProcAddress(hRealMSS32, "_AIL_digital_master_volume_level");
    pAIL_end_3D_sample = GetProcAddress(hRealMSS32, "_AIL_end_3D_sample");
    pAIL_end_sample = GetProcAddress(hRealMSS32, "_AIL_end_sample");
    pAIL_end_sequence = GetProcAddress(hRealMSS32, "_AIL_end_sequence");
    pAIL_enumerate_3D_provider_attributes = GetProcAddress(hRealMSS32, "_AIL_enumerate_3D_provider_attributes");
    pAIL_enumerate_3D_providers = GetProcAddress(hRealMSS32, "_AIL_enumerate_3D_providers");
    pAIL_enumerate_3D_sample_attributes = GetProcAddress(hRealMSS32, "_AIL_enumerate_3D_sample_attributes");
    pAIL_enumerate_filter_attributes = GetProcAddress(hRealMSS32, "_AIL_enumerate_filter_attributes");
    pAIL_enumerate_filter_sample_attributes = GetProcAddress(hRealMSS32, "_AIL_enumerate_filter_sample_attributes");
    pAIL_enumerate_filters = GetProcAddress(hRealMSS32, "_AIL_enumerate_filters");
    pAIL_extract_DLS = GetProcAddress(hRealMSS32, "_AIL_extract_DLS");
    pAIL_file_error = GetProcAddress(hRealMSS32, "_AIL_file_error");
    pAIL_file_read = GetProcAddress(hRealMSS32, "_AIL_file_read");
    pAIL_file_size = GetProcAddress(hRealMSS32, "_AIL_file_size");
    pAIL_file_type = GetProcAddress(hRealMSS32, "_AIL_file_type");
    pAIL_file_write = GetProcAddress(hRealMSS32, "_AIL_file_write");
    pAIL_filter_DLS_attribute = GetProcAddress(hRealMSS32, "_AIL_filter_DLS_attribute");
    pAIL_filter_DLS_with_XMI = GetProcAddress(hRealMSS32, "_AIL_filter_DLS_with_XMI");
    pAIL_filter_attribute = GetProcAddress(hRealMSS32, "_AIL_filter_attribute");
    pAIL_filter_sample_attribute = GetProcAddress(hRealMSS32, "_AIL_filter_sample_attribute");
    pAIL_filter_stream_attribute = GetProcAddress(hRealMSS32, "_AIL_filter_stream_attribute");
    pAIL_find_DLS = GetProcAddress(hRealMSS32, "_AIL_find_DLS");
    pAIL_get_DirectSound_info = GetProcAddress(hRealMSS32, "_AIL_get_DirectSound_info");
    pAIL_get_input_info = GetProcAddress(hRealMSS32, "_AIL_get_input_info");
    pAIL_get_preference = GetProcAddress(hRealMSS32, "_AIL_get_preference");
    pAIL_get_timer_highest_delay = GetProcAddress(hRealMSS32, "_AIL_get_timer_highest_delay");
    pAIL_init_sample = GetProcAddress(hRealMSS32, "_AIL_init_sample");
    pAIL_init_sequence = GetProcAddress(hRealMSS32, "_AIL_init_sequence");
    pAIL_last_error = GetProcAddress(hRealMSS32, "_AIL_last_error");
    pAIL_list_DLS = GetProcAddress(hRealMSS32, "_AIL_list_DLS");
    pAIL_list_MIDI = GetProcAddress(hRealMSS32, "_AIL_list_MIDI");
    pAIL_load_sample_buffer = GetProcAddress(hRealMSS32, "_AIL_load_sample_buffer");
    pAIL_lock = GetProcAddress(hRealMSS32, "_AIL_lock");
    pAIL_lock_channel = GetProcAddress(hRealMSS32, "_AIL_lock_channel");
    pAIL_lock_mutex = GetProcAddress(hRealMSS32, "_AIL_lock_mutex");
    pAIL_map_sequence_channel = GetProcAddress(hRealMSS32, "_AIL_map_sequence_channel");
    pAIL_mem_alloc_lock = GetProcAddress(hRealMSS32, "_AIL_mem_alloc_lock");
    pAIL_mem_free_lock = GetProcAddress(hRealMSS32, "_AIL_mem_free_lock");
    pAIL_mem_use_free = GetProcAddress(hRealMSS32, "_AIL_mem_use_free");
    pAIL_mem_use_malloc = GetProcAddress(hRealMSS32, "_AIL_mem_use_malloc");
    pAIL_merge_DLS_with_XMI = GetProcAddress(hRealMSS32, "_AIL_merge_DLS_with_XMI");
    pAIL_midiOutClose = GetProcAddress(hRealMSS32, "_AIL_midiOutClose");
    pAIL_midiOutOpen = GetProcAddress(hRealMSS32, "_AIL_midiOutOpen");
    pAIL_minimum_sample_buffer_size = GetProcAddress(hRealMSS32, "_AIL_minimum_sample_buffer_size");
    pAIL_ms_count = GetProcAddress(hRealMSS32, "_AIL_ms_count");
    pAIL_open_3D_listener = GetProcAddress(hRealMSS32, "_AIL_open_3D_listener");
    pAIL_open_3D_object = GetProcAddress(hRealMSS32, "_AIL_open_3D_object");
    pAIL_open_3D_provider = GetProcAddress(hRealMSS32, "_AIL_open_3D_provider");
    pAIL_open_XMIDI_driver = GetProcAddress(hRealMSS32, "_AIL_open_XMIDI_driver");
    pAIL_open_digital_driver = GetProcAddress(hRealMSS32, "_AIL_open_digital_driver");
    pAIL_open_filter = GetProcAddress(hRealMSS32, "_AIL_open_filter");
    pAIL_open_input = GetProcAddress(hRealMSS32, "_AIL_open_input");
    pAIL_open_stream = GetProcAddress(hRealMSS32, "_AIL_open_stream");
    pAIL_pause_stream = GetProcAddress(hRealMSS32, "_AIL_pause_stream");
    pAIL_primary_digital_driver = GetProcAddress(hRealMSS32, "_AIL_primary_digital_driver");
    pAIL_process_digital_audio = GetProcAddress(hRealMSS32, "_AIL_process_digital_audio");
    pAIL_quick_copy = GetProcAddress(hRealMSS32, "_AIL_quick_copy");
    pAIL_quick_halt = GetProcAddress(hRealMSS32, "_AIL_quick_halt");
    pAIL_quick_handles = GetProcAddress(hRealMSS32, "_AIL_quick_handles");
    pAIL_quick_load = GetProcAddress(hRealMSS32, "_AIL_quick_load");
    pAIL_quick_load_and_play = GetProcAddress(hRealMSS32, "_AIL_quick_load_and_play");
    pAIL_quick_load_mem = GetProcAddress(hRealMSS32, "_AIL_quick_load_mem");
    pAIL_quick_ms_length = GetProcAddress(hRealMSS32, "_AIL_quick_ms_length");
    pAIL_quick_ms_position = GetProcAddress(hRealMSS32, "_AIL_quick_ms_position");
    pAIL_quick_play = GetProcAddress(hRealMSS32, "_AIL_quick_play");
    pAIL_quick_set_low_pass_cut_off = GetProcAddress(hRealMSS32, "_AIL_quick_set_low_pass_cut_off");
    pAIL_quick_set_ms_position = GetProcAddress(hRealMSS32, "_AIL_quick_set_ms_position");
    pAIL_quick_set_reverb_levels = GetProcAddress(hRealMSS32, "_AIL_quick_set_reverb_levels");
    pAIL_quick_set_speed = GetProcAddress(hRealMSS32, "_AIL_quick_set_speed");
    pAIL_quick_set_volume = GetProcAddress(hRealMSS32, "_AIL_quick_set_volume");
    pAIL_quick_shutdown = GetProcAddress(hRealMSS32, "_AIL_quick_shutdown");
    pAIL_quick_startup = GetProcAddress(hRealMSS32, "_AIL_quick_startup");
    pAIL_quick_status = GetProcAddress(hRealMSS32, "_AIL_quick_status");
    pAIL_quick_type = GetProcAddress(hRealMSS32, "_AIL_quick_type");
    pAIL_quick_unload = GetProcAddress(hRealMSS32, "_AIL_quick_unload");
    pAIL_redbook_close = GetProcAddress(hRealMSS32, "_AIL_redbook_close");
    pAIL_redbook_eject = GetProcAddress(hRealMSS32, "_AIL_redbook_eject");
    pAIL_redbook_id = GetProcAddress(hRealMSS32, "_AIL_redbook_id");
    pAIL_redbook_open = GetProcAddress(hRealMSS32, "_AIL_redbook_open");
    pAIL_redbook_open_drive = GetProcAddress(hRealMSS32, "_AIL_redbook_open_drive");
    pAIL_redbook_pause = GetProcAddress(hRealMSS32, "_AIL_redbook_pause");
    pAIL_redbook_play = GetProcAddress(hRealMSS32, "_AIL_redbook_play");
    pAIL_redbook_position = GetProcAddress(hRealMSS32, "_AIL_redbook_position");
    pAIL_redbook_resume = GetProcAddress(hRealMSS32, "_AIL_redbook_resume");
    pAIL_redbook_retract = GetProcAddress(hRealMSS32, "_AIL_redbook_retract");
    pAIL_redbook_set_volume_level = GetProcAddress(hRealMSS32, "_AIL_redbook_set_volume_level");
    pAIL_redbook_status = GetProcAddress(hRealMSS32, "_AIL_redbook_status");
    pAIL_redbook_stop = GetProcAddress(hRealMSS32, "_AIL_redbook_stop");
    pAIL_redbook_track = GetProcAddress(hRealMSS32, "_AIL_redbook_track");
    pAIL_redbook_track_info = GetProcAddress(hRealMSS32, "_AIL_redbook_track_info");
    pAIL_redbook_tracks = GetProcAddress(hRealMSS32, "_AIL_redbook_tracks");
    pAIL_redbook_volume_level = GetProcAddress(hRealMSS32, "_AIL_redbook_volume_level");
    pAIL_register_3D_EOS_callback = GetProcAddress(hRealMSS32, "_AIL_register_3D_EOS_callback");
    pAIL_register_EOB_callback = GetProcAddress(hRealMSS32, "_AIL_register_EOB_callback");
    pAIL_register_EOF_callback = GetProcAddress(hRealMSS32, "_AIL_register_EOF_callback");
    pAIL_register_EOS_callback = GetProcAddress(hRealMSS32, "_AIL_register_EOS_callback");
    pAIL_register_ICA_array = GetProcAddress(hRealMSS32, "_AIL_register_ICA_array");
    pAIL_register_SOB_callback = GetProcAddress(hRealMSS32, "_AIL_register_SOB_callback");
    pAIL_register_beat_callback = GetProcAddress(hRealMSS32, "_AIL_register_beat_callback");
    pAIL_register_event_callback = GetProcAddress(hRealMSS32, "_AIL_register_event_callback");
    pAIL_register_prefix_callback = GetProcAddress(hRealMSS32, "_AIL_register_prefix_callback");
    pAIL_register_sequence_callback = GetProcAddress(hRealMSS32, "_AIL_register_sequence_callback");
    pAIL_register_stream_callback = GetProcAddress(hRealMSS32, "_AIL_register_stream_callback");
    pAIL_register_timbre_callback = GetProcAddress(hRealMSS32, "_AIL_register_timbre_callback");
    pAIL_register_timer = GetProcAddress(hRealMSS32, "_AIL_register_timer");
    pAIL_register_trigger_callback = GetProcAddress(hRealMSS32, "_AIL_register_trigger_callback");
    pAIL_release_3D_sample_handle = GetProcAddress(hRealMSS32, "_AIL_release_3D_sample_handle");
    pAIL_release_all_timers = GetProcAddress(hRealMSS32, "_AIL_release_all_timers");
    pAIL_release_channel = GetProcAddress(hRealMSS32, "_AIL_release_channel");
    pAIL_release_sample_handle = GetProcAddress(hRealMSS32, "_AIL_release_sample_handle");
    pAIL_release_sequence_handle = GetProcAddress(hRealMSS32, "_AIL_release_sequence_handle");
    pAIL_release_timer_handle = GetProcAddress(hRealMSS32, "_AIL_release_timer_handle");
    pAIL_request_EOB_ASI_reset = GetProcAddress(hRealMSS32, "_AIL_request_EOB_ASI_reset");
    pAIL_resume_3D_sample = GetProcAddress(hRealMSS32, "_AIL_resume_3D_sample");
    pAIL_resume_sample = GetProcAddress(hRealMSS32, "_AIL_resume_sample");
    pAIL_resume_sequence = GetProcAddress(hRealMSS32, "_AIL_resume_sequence");
    pAIL_sample_buffer_info = GetProcAddress(hRealMSS32, "_AIL_sample_buffer_info");
    pAIL_sample_buffer_ready = GetProcAddress(hRealMSS32, "_AIL_sample_buffer_ready");
    pAIL_sample_granularity = GetProcAddress(hRealMSS32, "_AIL_sample_granularity");
    pAIL_sample_loop_count = GetProcAddress(hRealMSS32, "_AIL_sample_loop_count");
    pAIL_sample_low_pass_cut_off = GetProcAddress(hRealMSS32, "_AIL_sample_low_pass_cut_off");
    pAIL_sample_ms_position = GetProcAddress(hRealMSS32, "_AIL_sample_ms_position");
    pAIL_sample_playback_rate = GetProcAddress(hRealMSS32, "_AIL_sample_playback_rate");
    pAIL_sample_position = GetProcAddress(hRealMSS32, "_AIL_sample_position");
    pAIL_sample_reverb_levels = GetProcAddress(hRealMSS32, "_AIL_sample_reverb_levels");
    pAIL_sample_status = GetProcAddress(hRealMSS32, "_AIL_sample_status");
    pAIL_sample_user_data = GetProcAddress(hRealMSS32, "_AIL_sample_user_data");
    pAIL_sample_volume_levels = GetProcAddress(hRealMSS32, "_AIL_sample_volume_levels");
    pAIL_sample_volume_pan = GetProcAddress(hRealMSS32, "_AIL_sample_volume_pan");
    pAIL_send_channel_voice_message = GetProcAddress(hRealMSS32, "_AIL_send_channel_voice_message");
    pAIL_send_sysex_message = GetProcAddress(hRealMSS32, "_AIL_send_sysex_message");
    pAIL_sequence_loop_count = GetProcAddress(hRealMSS32, "_AIL_sequence_loop_count");
    pAIL_sequence_ms_position = GetProcAddress(hRealMSS32, "_AIL_sequence_ms_position");
    pAIL_sequence_position = GetProcAddress(hRealMSS32, "_AIL_sequence_position");
    pAIL_sequence_status = GetProcAddress(hRealMSS32, "_AIL_sequence_status");
    pAIL_sequence_tempo = GetProcAddress(hRealMSS32, "_AIL_sequence_tempo");
    pAIL_sequence_user_data = GetProcAddress(hRealMSS32, "_AIL_sequence_user_data");
    pAIL_sequence_volume = GetProcAddress(hRealMSS32, "_AIL_sequence_volume");
    pAIL_serve = GetProcAddress(hRealMSS32, "_AIL_serve");
    pAIL_service_stream = GetProcAddress(hRealMSS32, "_AIL_service_stream");
    pAIL_set_3D_distance_factor = GetProcAddress(hRealMSS32, "_AIL_set_3D_distance_factor");
    pAIL_set_3D_doppler_factor = GetProcAddress(hRealMSS32, "_AIL_set_3D_doppler_factor");
    pAIL_set_3D_orientation = GetProcAddress(hRealMSS32, "_AIL_set_3D_orientation");
    pAIL_set_3D_position = GetProcAddress(hRealMSS32, "_AIL_set_3D_position");
    pAIL_set_3D_provider_preference = GetProcAddress(hRealMSS32, "_AIL_set_3D_provider_preference");
    pAIL_set_3D_rolloff_factor = GetProcAddress(hRealMSS32, "_AIL_set_3D_rolloff_factor");
    pAIL_set_3D_room_type = GetProcAddress(hRealMSS32, "_AIL_set_3D_room_type");
    pAIL_set_3D_sample_cone = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_cone");
    pAIL_set_3D_sample_distances = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_distances");
    pAIL_set_3D_sample_effects_level = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_effects_level");
    pAIL_set_3D_sample_exclusion = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_exclusion");
    pAIL_set_3D_sample_file = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_file");
    pAIL_set_3D_sample_info = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_info");
    pAIL_set_3D_sample_loop_block = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_loop_block");
    pAIL_set_3D_sample_loop_count = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_loop_count");
    pAIL_set_3D_sample_obstruction = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_obstruction");
    pAIL_set_3D_sample_occlusion = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_occlusion");
    pAIL_set_3D_sample_offset = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_offset");
    pAIL_set_3D_sample_playback_rate = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_playback_rate");
    pAIL_set_3D_sample_preference = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_preference");
    pAIL_set_3D_sample_volume = GetProcAddress(hRealMSS32, "_AIL_set_3D_sample_volume");
    pAIL_set_3D_speaker_type = GetProcAddress(hRealMSS32, "_AIL_set_3D_speaker_type");
    pAIL_set_3D_user_data = GetProcAddress(hRealMSS32, "_AIL_set_3D_user_data");
    pAIL_set_3D_velocity = GetProcAddress(hRealMSS32, "_AIL_set_3D_velocity");
    pAIL_set_3D_velocity_vector = GetProcAddress(hRealMSS32, "_AIL_set_3D_velocity_vector");
    pAIL_set_DLS_processor = GetProcAddress(hRealMSS32, "_AIL_set_DLS_processor");
    pAIL_set_DirectSound_HWND = GetProcAddress(hRealMSS32, "_AIL_set_DirectSound_HWND");
    pAIL_set_XMIDI_master_volume = GetProcAddress(hRealMSS32, "_AIL_set_XMIDI_master_volume");
    pAIL_set_digital_driver_processor = GetProcAddress(hRealMSS32, "_AIL_set_digital_driver_processor");
    pAIL_set_digital_master_reverb = GetProcAddress(hRealMSS32, "_AIL_set_digital_master_reverb");
    pAIL_set_digital_master_reverb_levels = GetProcAddress(hRealMSS32, "_AIL_set_digital_master_reverb_levels");
    pAIL_set_digital_master_room_type = GetProcAddress(hRealMSS32, "_AIL_set_digital_master_room_type");
    pAIL_set_digital_master_volume_level = GetProcAddress(hRealMSS32, "_AIL_set_digital_master_volume_level");
    pAIL_set_error = GetProcAddress(hRealMSS32, "_AIL_set_error");
    pAIL_set_file_async_callbacks = GetProcAddress(hRealMSS32, "_AIL_set_file_async_callbacks");
    pAIL_set_file_callbacks = GetProcAddress(hRealMSS32, "_AIL_set_file_callbacks@16");
    pAIL_set_filter_DLS_preference = GetProcAddress(hRealMSS32, "_AIL_set_filter_DLS_preference");
    pAIL_set_filter_preference = GetProcAddress(hRealMSS32, "_AIL_set_filter_preference");
    pAIL_set_filter_sample_preference = GetProcAddress(hRealMSS32, "_AIL_set_filter_sample_preference");
    pAIL_set_filter_stream_preference = GetProcAddress(hRealMSS32, "_AIL_set_filter_stream_preference");
    pAIL_set_input_state = GetProcAddress(hRealMSS32, "_AIL_set_input_state");
    pAIL_set_named_sample_file = GetProcAddress(hRealMSS32, "_AIL_set_named_sample_file");
    pAIL_set_preference = GetProcAddress(hRealMSS32, "_AIL_set_preference");
    pAIL_set_redist_directory = GetProcAddress(hRealMSS32, "_AIL_set_redist_directory@4");
    pAIL_set_sample_address = GetProcAddress(hRealMSS32, "_AIL_set_sample_address");
    pAIL_set_sample_adpcm_block_size = GetProcAddress(hRealMSS32, "_AIL_set_sample_adpcm_block_size");
    pAIL_set_sample_file = GetProcAddress(hRealMSS32, "_AIL_set_sample_file");
    pAIL_set_sample_loop_block = GetProcAddress(hRealMSS32, "_AIL_set_sample_loop_block");
    pAIL_set_sample_loop_count = GetProcAddress(hRealMSS32, "_AIL_set_sample_loop_count");
    pAIL_set_sample_low_pass_cut_off = GetProcAddress(hRealMSS32, "_AIL_set_sample_low_pass_cut_off");
    pAIL_set_sample_ms_position = GetProcAddress(hRealMSS32, "_AIL_set_sample_ms_position");
    pAIL_set_sample_playback_rate = GetProcAddress(hRealMSS32, "_AIL_set_sample_playback_rate");
    pAIL_set_sample_position = GetProcAddress(hRealMSS32, "_AIL_set_sample_position");
    pAIL_set_sample_processor = GetProcAddress(hRealMSS32, "_AIL_set_sample_processor");
    pAIL_set_sample_reverb_levels = GetProcAddress(hRealMSS32, "_AIL_set_sample_reverb_levels");
    pAIL_set_sample_type = GetProcAddress(hRealMSS32, "_AIL_set_sample_type");
    pAIL_set_sample_user_data = GetProcAddress(hRealMSS32, "_AIL_set_sample_user_data");
    pAIL_set_sample_volume_levels = GetProcAddress(hRealMSS32, "_AIL_set_sample_volume_levels");
    pAIL_set_sample_volume_pan = GetProcAddress(hRealMSS32, "_AIL_set_sample_volume_pan");
    pAIL_set_sequence_loop_count = GetProcAddress(hRealMSS32, "_AIL_set_sequence_loop_count");
    pAIL_set_sequence_ms_position = GetProcAddress(hRealMSS32, "_AIL_set_sequence_ms_position");
    pAIL_set_sequence_tempo = GetProcAddress(hRealMSS32, "_AIL_set_sequence_tempo");
    pAIL_set_sequence_user_data = GetProcAddress(hRealMSS32, "_AIL_set_sequence_user_data");
    pAIL_set_sequence_volume = GetProcAddress(hRealMSS32, "_AIL_set_sequence_volume");
    pAIL_set_stream_loop_block = GetProcAddress(hRealMSS32, "_AIL_set_stream_loop_block");
    pAIL_set_stream_loop_count = GetProcAddress(hRealMSS32, "_AIL_set_stream_loop_count");
    pAIL_set_stream_low_pass_cut_off = GetProcAddress(hRealMSS32, "_AIL_set_stream_low_pass_cut_off");
    pAIL_set_stream_ms_position = GetProcAddress(hRealMSS32, "_AIL_set_stream_ms_position");
    pAIL_set_stream_playback_rate = GetProcAddress(hRealMSS32, "_AIL_set_stream_playback_rate");
    pAIL_set_stream_position = GetProcAddress(hRealMSS32, "_AIL_set_stream_position");
    pAIL_set_stream_processor = GetProcAddress(hRealMSS32, "_AIL_set_stream_processor");
    pAIL_set_stream_reverb_levels = GetProcAddress(hRealMSS32, "_AIL_set_stream_reverb_levels");
    pAIL_set_stream_user_data = GetProcAddress(hRealMSS32, "_AIL_set_stream_user_data");
    pAIL_set_stream_volume_levels = GetProcAddress(hRealMSS32, "_AIL_set_stream_volume_levels");
    pAIL_set_stream_volume_pan = GetProcAddress(hRealMSS32, "_AIL_set_stream_volume_pan");
    pAIL_set_timer_divisor = GetProcAddress(hRealMSS32, "_AIL_set_timer_divisor");
    pAIL_set_timer_frequency = GetProcAddress(hRealMSS32, "_AIL_set_timer_frequency");
    pAIL_set_timer_period = GetProcAddress(hRealMSS32, "_AIL_set_timer_period");
    pAIL_set_timer_user = GetProcAddress(hRealMSS32, "_AIL_set_timer_user");
    pAIL_shutdown = GetProcAddress(hRealMSS32, "_AIL_shutdown");
    pAIL_size_processed_digital_audio = GetProcAddress(hRealMSS32, "_AIL_size_processed_digital_audio");
    pAIL_start_3D_sample = GetProcAddress(hRealMSS32, "_AIL_start_3D_sample");
    pAIL_start_all_timers = GetProcAddress(hRealMSS32, "_AIL_start_all_timers");
    pAIL_start_sample = GetProcAddress(hRealMSS32, "_AIL_start_sample");
    pAIL_start_sequence = GetProcAddress(hRealMSS32, "_AIL_start_sequence");
    pAIL_start_stream = GetProcAddress(hRealMSS32, "_AIL_start_stream");
    pAIL_start_timer = GetProcAddress(hRealMSS32, "_AIL_start_timer");
    pAIL_startup = GetProcAddress(hRealMSS32, "_AIL_startup");
    pAIL_stop_3D_sample = GetProcAddress(hRealMSS32, "_AIL_stop_3D_sample");
    pAIL_stop_all_timers = GetProcAddress(hRealMSS32, "_AIL_stop_all_timers");
    pAIL_stop_sample = GetProcAddress(hRealMSS32, "_AIL_stop_sample");
    pAIL_stop_sequence = GetProcAddress(hRealMSS32, "_AIL_stop_sequence");
    pAIL_stop_timer = GetProcAddress(hRealMSS32, "_AIL_stop_timer");
    pAIL_stream_info = GetProcAddress(hRealMSS32, "_AIL_stream_info");
    pAIL_stream_loop_count = GetProcAddress(hRealMSS32, "_AIL_stream_loop_count");
    pAIL_stream_low_pass_cut_off = GetProcAddress(hRealMSS32, "_AIL_stream_low_pass_cut_off");
    pAIL_stream_ms_position = GetProcAddress(hRealMSS32, "_AIL_stream_ms_position");
    pAIL_stream_playback_rate = GetProcAddress(hRealMSS32, "_AIL_stream_playback_rate");
    pAIL_stream_position = GetProcAddress(hRealMSS32, "_AIL_stream_position");
    pAIL_stream_reverb_levels = GetProcAddress(hRealMSS32, "_AIL_stream_reverb_levels");
    pAIL_stream_status = GetProcAddress(hRealMSS32, "_AIL_stream_status");
    pAIL_stream_user_data = GetProcAddress(hRealMSS32, "_AIL_stream_user_data");
    pAIL_stream_volume_levels = GetProcAddress(hRealMSS32, "_AIL_stream_volume_levels");
    pAIL_stream_volume_pan = GetProcAddress(hRealMSS32, "_AIL_stream_volume_pan");
    pAIL_true_sequence_channel = GetProcAddress(hRealMSS32, "_AIL_true_sequence_channel");
    pAIL_unlock = GetProcAddress(hRealMSS32, "_AIL_unlock");
    pAIL_unlock_mutex = GetProcAddress(hRealMSS32, "_AIL_unlock_mutex");
    pAIL_update_3D_position = GetProcAddress(hRealMSS32, "_AIL_update_3D_position");
    pAIL_us_count = GetProcAddress(hRealMSS32, "_AIL_us_count");
    pAIL_waveOutClose = GetProcAddress(hRealMSS32, "_AIL_waveOutClose");
    pAIL_waveOutOpen = GetProcAddress(hRealMSS32, "_AIL_waveOutOpen");
    pDLSMSSGetCPU = GetProcAddress(hRealMSS32, "_DLSMSSGetCPU");
    pMIX_RIB_MAIN = GetProcAddress(hRealMSS32, "_MIX_RIB_MAIN");
    pRIB_enumerate_providers = GetProcAddress(hRealMSS32, "_RIB_enumerate_providers");
    pRIB_find_file_dec_provider = GetProcAddress(hRealMSS32, "_RIB_find_file_dec_provider");
    pRIB_find_files_provider = GetProcAddress(hRealMSS32, "_RIB_find_files_provider");
    pRIB_find_provider = GetProcAddress(hRealMSS32, "_RIB_find_provider");
    pRIB_load_application_providers = GetProcAddress(hRealMSS32, "_RIB_load_application_providers");
    pRIB_load_static_provider_library = GetProcAddress(hRealMSS32, "_RIB_load_static_provider_library");
    pRIB_provider_system_data = GetProcAddress(hRealMSS32, "_RIB_provider_system_data");
    pRIB_provider_user_data = GetProcAddress(hRealMSS32, "_RIB_provider_user_data");
    pRIB_set_provider_system_data = GetProcAddress(hRealMSS32, "_RIB_set_provider_system_data");
    pRIB_set_provider_user_data = GetProcAddress(hRealMSS32, "_RIB_set_provider_user_data");
    pstream_background = GetProcAddress(hRealMSS32, "stream_background");
    // these shits */

// Thanks CoDExtended
	pAIL_debug_printf = GetProcAddress(hMSS, "AIL_debug_printf");
	pAIL_sprintf = GetProcAddress(hMSS, "AIL_sprintf");
	pDLSClose = GetProcAddress(hMSS, "DLSClose");
	pDLSCompactMemory = GetProcAddress(hMSS, "DLSCompactMemory");
	pDLSGetInfo = GetProcAddress(hMSS, "DLSGetInfo");
	pDLSLoadFile = GetProcAddress(hMSS, "DLSLoadFile");
	pDLSLoadMemFile = GetProcAddress(hMSS, "DLSLoadMemFile");
	pDLSMSSOpen = GetProcAddress(hMSS, "DLSMSSOpen");
	pDLSSetAttribute = GetProcAddress(hMSS, "DLSSetAttribute");
	pDLSUnloadAll = GetProcAddress(hMSS, "DLSUnloadAll");
	pDLSUnloadFile = GetProcAddress(hMSS, "DLSUnloadFile");
	pRIB_alloc_provider_handle = GetProcAddress(hMSS, "RIB_alloc_provider_handle");
	pRIB_enumerate_interface = GetProcAddress(hMSS, "RIB_enumerate_interface");
	pRIB_error = GetProcAddress(hMSS, "RIB_error");
	pRIB_find_file_provider = GetProcAddress(hMSS, "RIB_find_file_provider");
	pRIB_free_provider_handle = GetProcAddress(hMSS, "RIB_free_provider_handle");
	pRIB_free_provider_library = GetProcAddress(hMSS, "RIB_free_provider_library");
	pRIB_load_provider_library = GetProcAddress(hMSS, "RIB_load_provider_library");
	pRIB_register_interface = GetProcAddress(hMSS, "RIB_register_interface");
	pRIB_request_interface = GetProcAddress(hMSS, "RIB_request_interface");
	pRIB_request_interface_entry = GetProcAddress(hMSS, "RIB_request_interface_entry");
	pRIB_type_string = GetProcAddress(hMSS, "RIB_type_string");
	pRIB_unregister_interface = GetProcAddress(hMSS, "RIB_unregister_interface");
	pAIL_3D_distance_factor = GetProcAddress(hMSS, "_AIL_3D_distance_factor@4");
	pAIL_3D_doppler_factor = GetProcAddress(hMSS, "_AIL_3D_doppler_factor@4");
	pAIL_3D_orientation = GetProcAddress(hMSS, "_AIL_3D_orientation@28");
	pAIL_3D_position = GetProcAddress(hMSS, "_AIL_3D_position@16");
	pAIL_3D_provider_attribute = GetProcAddress(hMSS, "_AIL_3D_provider_attribute@12");
	pAIL_3D_rolloff_factor = GetProcAddress(hMSS, "_AIL_3D_rolloff_factor@4");
	pAIL_3D_room_type = GetProcAddress(hMSS, "_AIL_3D_room_type@4");
	pAIL_3D_sample_attribute = GetProcAddress(hMSS, "_AIL_3D_sample_attribute@12");
	pAIL_3D_sample_cone = GetProcAddress(hMSS, "_AIL_3D_sample_cone@16");
	pAIL_3D_sample_distances = GetProcAddress(hMSS, "_AIL_3D_sample_distances@12");
	pAIL_3D_sample_effects_level = GetProcAddress(hMSS, "_AIL_3D_sample_effects_level@4");
	pAIL_3D_sample_exclusion = GetProcAddress(hMSS, "_AIL_3D_sample_exclusion@4");
	pAIL_3D_sample_length = GetProcAddress(hMSS, "_AIL_3D_sample_length@4");
	pAIL_3D_sample_loop_count = GetProcAddress(hMSS, "_AIL_3D_sample_loop_count@4");
	pAIL_3D_sample_obstruction = GetProcAddress(hMSS, "_AIL_3D_sample_obstruction@4");
	pAIL_3D_sample_occlusion = GetProcAddress(hMSS, "_AIL_3D_sample_occlusion@4");
	pAIL_3D_sample_offset = GetProcAddress(hMSS, "_AIL_3D_sample_offset@4");
	pAIL_3D_sample_playback_rate = GetProcAddress(hMSS, "_AIL_3D_sample_playback_rate@4");
	pAIL_3D_sample_status = GetProcAddress(hMSS, "_AIL_3D_sample_status@4");
	pAIL_3D_sample_volume = GetProcAddress(hMSS, "_AIL_3D_sample_volume@4");
	pAIL_3D_speaker_type = GetProcAddress(hMSS, "_AIL_3D_speaker_type@4");
	pAIL_3D_user_data = GetProcAddress(hMSS, "_AIL_3D_user_data@8");
	pAIL_3D_velocity = GetProcAddress(hMSS, "_AIL_3D_velocity@16");
	pAIL_DLS_close = GetProcAddress(hMSS, "_AIL_DLS_close@8");
	pAIL_DLS_compact = GetProcAddress(hMSS, "_AIL_DLS_compact@4");
	pAIL_DLS_get_info = GetProcAddress(hMSS, "_AIL_DLS_get_info@12");
	pAIL_DLS_get_reverb_levels = GetProcAddress(hMSS, "_AIL_DLS_get_reverb_levels@12");
	pAIL_DLS_load_file = GetProcAddress(hMSS, "_AIL_DLS_load_file@12");
	pAIL_DLS_load_memory = GetProcAddress(hMSS, "_AIL_DLS_load_memory@12");
	pAIL_DLS_open = GetProcAddress(hMSS, "_AIL_DLS_open@28");
	pAIL_DLS_set_reverb_levels = GetProcAddress(hMSS, "_AIL_DLS_set_reverb_levels@12");
	pAIL_DLS_unload = GetProcAddress(hMSS, "_AIL_DLS_unload@8");
	pAIL_HWND = GetProcAddress(hMSS, "_AIL_HWND@0");
	pAIL_MIDI_handle_reacquire = GetProcAddress(hMSS, "_AIL_MIDI_handle_reacquire@4");
	pAIL_MIDI_handle_release = GetProcAddress(hMSS, "_AIL_MIDI_handle_release@4");
	pAIL_MIDI_to_XMI = GetProcAddress(hMSS, "_AIL_MIDI_to_XMI@20");
	pAIL_MMX_available = GetProcAddress(hMSS, "_AIL_MMX_available@0");
	pAIL_WAV_file_write = GetProcAddress(hMSS, "_AIL_WAV_file_write@20");
	pAIL_WAV_info = GetProcAddress(hMSS, "_AIL_WAV_info@8");
	pAIL_XMIDI_master_volume = GetProcAddress(hMSS, "_AIL_XMIDI_master_volume@4");
	pAIL_active_3D_sample_count = GetProcAddress(hMSS, "_AIL_active_3D_sample_count@4");
	pAIL_active_sample_count = GetProcAddress(hMSS, "_AIL_active_sample_count@4");
	pAIL_active_sequence_count = GetProcAddress(hMSS, "_AIL_active_sequence_count@4");
	pAIL_allocate_3D_sample_handle = GetProcAddress(hMSS, "_AIL_allocate_3D_sample_handle@4");
	pAIL_allocate_file_sample = GetProcAddress(hMSS, "_AIL_allocate_file_sample@12");
	pAIL_allocate_sample_handle = GetProcAddress(hMSS, "_AIL_allocate_sample_handle@4");
	pAIL_allocate_sequence_handle = GetProcAddress(hMSS, "_AIL_allocate_sequence_handle@4");
	pAIL_auto_service_stream = GetProcAddress(hMSS, "_AIL_auto_service_stream@8");
	pAIL_auto_update_3D_position = GetProcAddress(hMSS, "_AIL_auto_update_3D_position@8");
	pAIL_background = GetProcAddress(hMSS, "_AIL_background@0");
	pAIL_branch_index = GetProcAddress(hMSS, "_AIL_branch_index@8");
	pAIL_channel_notes = GetProcAddress(hMSS, "_AIL_channel_notes@8");
	pAIL_close_3D_listener = GetProcAddress(hMSS, "_AIL_close_3D_listener@4");
	pAIL_close_3D_object = GetProcAddress(hMSS, "_AIL_close_3D_object@4");
	pAIL_close_3D_provider = GetProcAddress(hMSS, "_AIL_close_3D_provider@4");
	pAIL_close_XMIDI_driver = GetProcAddress(hMSS, "_AIL_close_XMIDI_driver@4");
	pAIL_close_digital_driver = GetProcAddress(hMSS, "_AIL_close_digital_driver@4");
	pAIL_close_filter = GetProcAddress(hMSS, "_AIL_close_filter@4");
	pAIL_close_input = GetProcAddress(hMSS, "_AIL_close_input@4");
	pAIL_close_stream = GetProcAddress(hMSS, "_AIL_close_stream@4");
	pAIL_compress_ADPCM = GetProcAddress(hMSS, "_AIL_compress_ADPCM@12");
	pAIL_compress_ASI = GetProcAddress(hMSS, "_AIL_compress_ASI@20");
	pAIL_compress_DLS = GetProcAddress(hMSS, "_AIL_compress_DLS@20");
	pAIL_controller_value = GetProcAddress(hMSS, "_AIL_controller_value@12");
	pAIL_create_wave_synthesizer = GetProcAddress(hMSS, "_AIL_create_wave_synthesizer@16");
	pAIL_decompress_ADPCM = GetProcAddress(hMSS, "_AIL_decompress_ADPCM@12");
	pAIL_decompress_ASI = GetProcAddress(hMSS, "_AIL_decompress_ASI@24");
	pAIL_delay = GetProcAddress(hMSS, "_AIL_delay@4");
	pAIL_destroy_wave_synthesizer = GetProcAddress(hMSS, "_AIL_destroy_wave_synthesizer@4");
	pAIL_digital_CPU_percent = GetProcAddress(hMSS, "_AIL_digital_CPU_percent@4");
	pAIL_digital_configuration = GetProcAddress(hMSS, "_AIL_digital_configuration@16");
	pAIL_digital_handle_reacquire = GetProcAddress(hMSS, "_AIL_digital_handle_reacquire@4");
	pAIL_digital_handle_release = GetProcAddress(hMSS, "_AIL_digital_handle_release@4");
	pAIL_digital_latency = GetProcAddress(hMSS, "_AIL_digital_latency@4");
	pAIL_digital_master_reverb = GetProcAddress(hMSS, "_AIL_digital_master_reverb@16");
	pAIL_digital_master_reverb_levels = GetProcAddress(hMSS, "_AIL_digital_master_reverb_levels@12");
	pAIL_digital_master_volume_level = GetProcAddress(hMSS, "_AIL_digital_master_volume_level@4");
	pAIL_end_3D_sample = GetProcAddress(hMSS, "_AIL_end_3D_sample@4");
	pAIL_end_sample = GetProcAddress(hMSS, "_AIL_end_sample@4");
	pAIL_end_sequence = GetProcAddress(hMSS, "_AIL_end_sequence@4");
	pAIL_enumerate_3D_provider_attributes = GetProcAddress(hMSS, "_AIL_enumerate_3D_provider_attributes@12");
	pAIL_enumerate_3D_providers = GetProcAddress(hMSS, "_AIL_enumerate_3D_providers@12");
	pAIL_enumerate_3D_sample_attributes = GetProcAddress(hMSS, "_AIL_enumerate_3D_sample_attributes@12");
	pAIL_enumerate_filter_attributes = GetProcAddress(hMSS, "_AIL_enumerate_filter_attributes@12");
	pAIL_enumerate_filter_sample_attributes = GetProcAddress(hMSS, "_AIL_enumerate_filter_sample_attributes@12");
	pAIL_enumerate_filters = GetProcAddress(hMSS, "_AIL_enumerate_filters@12");
	pAIL_extract_DLS = GetProcAddress(hMSS, "_AIL_extract_DLS@28");
	pAIL_file_error = GetProcAddress(hMSS, "_AIL_file_error@0");
	pAIL_file_read = GetProcAddress(hMSS, "_AIL_file_read@8");
	pAIL_file_size = GetProcAddress(hMSS, "_AIL_file_size@4");
	pAIL_file_type = GetProcAddress(hMSS, "_AIL_file_type@8");
	pAIL_file_write = GetProcAddress(hMSS, "_AIL_file_write@12");
	pAIL_filter_DLS_attribute = GetProcAddress(hMSS, "_AIL_filter_DLS_attribute@12");
	pAIL_filter_DLS_with_XMI = GetProcAddress(hMSS, "_AIL_filter_DLS_with_XMI@24");
	pAIL_filter_attribute = GetProcAddress(hMSS, "_AIL_filter_attribute@12");
	pAIL_filter_sample_attribute = GetProcAddress(hMSS, "_AIL_filter_sample_attribute@12");
	pAIL_filter_stream_attribute = GetProcAddress(hMSS, "_AIL_filter_stream_attribute@12");
	pAIL_find_DLS = GetProcAddress(hMSS, "_AIL_find_DLS@24");
	pAIL_get_DirectSound_info = GetProcAddress(hMSS, "_AIL_get_DirectSound_info@12");
	pAIL_get_input_info = GetProcAddress(hMSS, "_AIL_get_input_info@4");
	pAIL_get_preference = GetProcAddress(hMSS, "_AIL_get_preference@4");
	pAIL_get_timer_highest_delay = GetProcAddress(hMSS, "_AIL_get_timer_highest_delay@0");
	pAIL_init_sample = GetProcAddress(hMSS, "_AIL_init_sample@4");
	pAIL_init_sequence = GetProcAddress(hMSS, "_AIL_init_sequence@12");
	pAIL_last_error = GetProcAddress(hMSS, "_AIL_last_error@0");
	pAIL_list_DLS = GetProcAddress(hMSS, "_AIL_list_DLS@20");
	pAIL_list_MIDI = GetProcAddress(hMSS, "_AIL_list_MIDI@20");
	pAIL_load_sample_buffer = GetProcAddress(hMSS, "_AIL_load_sample_buffer@16");
	pAIL_lock = GetProcAddress(hMSS, "_AIL_lock@0");
	pAIL_lock_channel = GetProcAddress(hMSS, "_AIL_lock_channel@4");
	pAIL_lock_mutex = GetProcAddress(hMSS, "_AIL_lock_mutex@0");
	pAIL_map_sequence_channel = GetProcAddress(hMSS, "_AIL_map_sequence_channel@12");
	pAIL_mem_alloc_lock = GetProcAddress(hMSS, "_AIL_mem_alloc_lock@4");
	pAIL_mem_free_lock = GetProcAddress(hMSS, "_AIL_mem_free_lock@4");
	pAIL_mem_use_free = GetProcAddress(hMSS, "_AIL_mem_use_free@4");
	pAIL_mem_use_malloc = GetProcAddress(hMSS, "_AIL_mem_use_malloc@4");
	pAIL_merge_DLS_with_XMI = GetProcAddress(hMSS, "_AIL_merge_DLS_with_XMI@16");
	pAIL_midiOutClose = GetProcAddress(hMSS, "_AIL_midiOutClose@4");
	pAIL_midiOutOpen = GetProcAddress(hMSS, "_AIL_midiOutOpen@12");
	pAIL_minimum_sample_buffer_size = GetProcAddress(hMSS, "_AIL_minimum_sample_buffer_size@12");
	pAIL_ms_count = GetProcAddress(hMSS, "_AIL_ms_count@0");
	pAIL_open_3D_listener = GetProcAddress(hMSS, "_AIL_open_3D_listener@4");
	pAIL_open_3D_object = GetProcAddress(hMSS, "_AIL_open_3D_object@4");
	pAIL_open_3D_provider = GetProcAddress(hMSS, "_AIL_open_3D_provider@4");
	pAIL_open_XMIDI_driver = GetProcAddress(hMSS, "_AIL_open_XMIDI_driver@4");
	pAIL_open_digital_driver = GetProcAddress(hMSS, "_AIL_open_digital_driver@16");
	pAIL_open_filter = GetProcAddress(hMSS, "_AIL_open_filter@8");
	pAIL_open_input = GetProcAddress(hMSS, "_AIL_open_input@4");
	pAIL_open_stream = GetProcAddress(hMSS, "_AIL_open_stream@12");
	pAIL_pause_stream = GetProcAddress(hMSS, "_AIL_pause_stream@8");
	pAIL_primary_digital_driver = GetProcAddress(hMSS, "_AIL_primary_digital_driver@4");
	pAIL_process_digital_audio = GetProcAddress(hMSS, "_AIL_process_digital_audio@24");
	pAIL_quick_copy = GetProcAddress(hMSS, "_AIL_quick_copy@4");
	pAIL_quick_halt = GetProcAddress(hMSS, "_AIL_quick_halt@4");
	pAIL_quick_handles = GetProcAddress(hMSS, "_AIL_quick_handles@12");
	pAIL_quick_load = GetProcAddress(hMSS, "_AIL_quick_load@4");
	pAIL_quick_load_and_play = GetProcAddress(hMSS, "_AIL_quick_load_and_play@12");
	pAIL_quick_load_mem = GetProcAddress(hMSS, "_AIL_quick_load_mem@8");
	pAIL_quick_ms_length = GetProcAddress(hMSS, "_AIL_quick_ms_length@4");
	pAIL_quick_ms_position = GetProcAddress(hMSS, "_AIL_quick_ms_position@4");
	pAIL_quick_play = GetProcAddress(hMSS, "_AIL_quick_play@8");
	pAIL_quick_set_low_pass_cut_off = GetProcAddress(hMSS, "_AIL_quick_set_low_pass_cut_off@8");
	pAIL_quick_set_ms_position = GetProcAddress(hMSS, "_AIL_quick_set_ms_position@8");
	pAIL_quick_set_reverb_levels = GetProcAddress(hMSS, "_AIL_quick_set_reverb_levels@12");
	pAIL_quick_set_speed = GetProcAddress(hMSS, "_AIL_quick_set_speed@8");
	pAIL_quick_set_volume = GetProcAddress(hMSS, "_AIL_quick_set_volume@12");
	pAIL_quick_shutdown = GetProcAddress(hMSS, "_AIL_quick_shutdown@0");
	pAIL_quick_startup = GetProcAddress(hMSS, "_AIL_quick_startup@20");
	pAIL_quick_status = GetProcAddress(hMSS, "_AIL_quick_status@4");
	pAIL_quick_type = GetProcAddress(hMSS, "_AIL_quick_type@4");
	pAIL_quick_unload = GetProcAddress(hMSS, "_AIL_quick_unload@4");
	pAIL_redbook_close = GetProcAddress(hMSS, "_AIL_redbook_close@4");
	pAIL_redbook_eject = GetProcAddress(hMSS, "_AIL_redbook_eject@4");
	pAIL_redbook_id = GetProcAddress(hMSS, "_AIL_redbook_id@4");
	pAIL_redbook_open = GetProcAddress(hMSS, "_AIL_redbook_open@4");
	pAIL_redbook_open_drive = GetProcAddress(hMSS, "_AIL_redbook_open_drive@4");
	pAIL_redbook_pause = GetProcAddress(hMSS, "_AIL_redbook_pause@4");
	pAIL_redbook_play = GetProcAddress(hMSS, "_AIL_redbook_play@12");
	pAIL_redbook_position = GetProcAddress(hMSS, "_AIL_redbook_position@4");
	pAIL_redbook_resume = GetProcAddress(hMSS, "_AIL_redbook_resume@4");
	pAIL_redbook_retract = GetProcAddress(hMSS, "_AIL_redbook_retract@4");
	pAIL_redbook_set_volume_level = GetProcAddress(hMSS, "_AIL_redbook_set_volume_level@8");
	pAIL_redbook_status = GetProcAddress(hMSS, "_AIL_redbook_status@4");
	pAIL_redbook_stop = GetProcAddress(hMSS, "_AIL_redbook_stop@4");
	pAIL_redbook_track = GetProcAddress(hMSS, "_AIL_redbook_track@4");
	pAIL_redbook_track_info = GetProcAddress(hMSS, "_AIL_redbook_track_info@16");
	pAIL_redbook_tracks = GetProcAddress(hMSS, "_AIL_redbook_tracks@4");
	pAIL_redbook_volume_level = GetProcAddress(hMSS, "_AIL_redbook_volume_level@4");
	pAIL_register_3D_EOS_callback = GetProcAddress(hMSS, "_AIL_register_3D_EOS_callback@8");
	pAIL_register_EOB_callback = GetProcAddress(hMSS, "_AIL_register_EOB_callback@8");
	pAIL_register_EOF_callback = GetProcAddress(hMSS, "_AIL_register_EOF_callback@8");
	pAIL_register_EOS_callback = GetProcAddress(hMSS, "_AIL_register_EOS_callback@8");
	pAIL_register_ICA_array = GetProcAddress(hMSS, "_AIL_register_ICA_array@8");
	pAIL_register_SOB_callback = GetProcAddress(hMSS, "_AIL_register_SOB_callback@8");
	pAIL_register_beat_callback = GetProcAddress(hMSS, "_AIL_register_beat_callback@8");
	pAIL_register_event_callback = GetProcAddress(hMSS, "_AIL_register_event_callback@8");
	pAIL_register_prefix_callback = GetProcAddress(hMSS, "_AIL_register_prefix_callback@8");
	pAIL_register_sequence_callback = GetProcAddress(hMSS, "_AIL_register_sequence_callback@8");
	pAIL_register_stream_callback = GetProcAddress(hMSS, "_AIL_register_stream_callback@8");
	pAIL_register_timbre_callback = GetProcAddress(hMSS, "_AIL_register_timbre_callback@8");
	pAIL_register_timer = GetProcAddress(hMSS, "_AIL_register_timer@4");
	pAIL_register_trigger_callback = GetProcAddress(hMSS, "_AIL_register_trigger_callback@8");
	pAIL_release_3D_sample_handle = GetProcAddress(hMSS, "_AIL_release_3D_sample_handle@4");
	pAIL_release_all_timers = GetProcAddress(hMSS, "_AIL_release_all_timers@0");
	pAIL_release_channel = GetProcAddress(hMSS, "_AIL_release_channel@8");
	pAIL_release_sample_handle = GetProcAddress(hMSS, "_AIL_release_sample_handle@4");
	pAIL_release_sequence_handle = GetProcAddress(hMSS, "_AIL_release_sequence_handle@4");
	pAIL_release_timer_handle = GetProcAddress(hMSS, "_AIL_release_timer_handle@4");
	pAIL_request_EOB_ASI_reset = GetProcAddress(hMSS, "_AIL_request_EOB_ASI_reset@8");
	pAIL_resume_3D_sample = GetProcAddress(hMSS, "_AIL_resume_3D_sample@4");
	pAIL_resume_sample = GetProcAddress(hMSS, "_AIL_resume_sample@4");
	pAIL_resume_sequence = GetProcAddress(hMSS, "_AIL_resume_sequence@4");
	pAIL_sample_buffer_info = GetProcAddress(hMSS, "_AIL_sample_buffer_info@20");
	pAIL_sample_buffer_ready = GetProcAddress(hMSS, "_AIL_sample_buffer_ready@4");
	pAIL_sample_granularity = GetProcAddress(hMSS, "_AIL_sample_granularity@4");
	pAIL_sample_loop_count = GetProcAddress(hMSS, "_AIL_sample_loop_count@4");
	pAIL_sample_low_pass_cut_off = GetProcAddress(hMSS, "_AIL_sample_low_pass_cut_off@4");
	pAIL_sample_ms_position = GetProcAddress(hMSS, "_AIL_sample_ms_position@12");
	pAIL_sample_playback_rate = GetProcAddress(hMSS, "_AIL_sample_playback_rate@4");
	pAIL_sample_position = GetProcAddress(hMSS, "_AIL_sample_position@4");
	pAIL_sample_reverb_levels = GetProcAddress(hMSS, "_AIL_sample_reverb_levels@12");
	pAIL_sample_status = GetProcAddress(hMSS, "_AIL_sample_status@4");
	pAIL_sample_user_data = GetProcAddress(hMSS, "_AIL_sample_user_data@8");
	pAIL_sample_volume_levels = GetProcAddress(hMSS, "_AIL_sample_volume_levels@12");
	pAIL_sample_volume_pan = GetProcAddress(hMSS, "_AIL_sample_volume_pan@12");
	pAIL_send_channel_voice_message = GetProcAddress(hMSS, "_AIL_send_channel_voice_message@20");
	pAIL_send_sysex_message = GetProcAddress(hMSS, "_AIL_send_sysex_message@8");
	pAIL_sequence_loop_count = GetProcAddress(hMSS, "_AIL_sequence_loop_count@4");
	pAIL_sequence_ms_position = GetProcAddress(hMSS, "_AIL_sequence_ms_position@12");
	pAIL_sequence_position = GetProcAddress(hMSS, "_AIL_sequence_position@12");
	pAIL_sequence_status = GetProcAddress(hMSS, "_AIL_sequence_status@4");
	pAIL_sequence_tempo = GetProcAddress(hMSS, "_AIL_sequence_tempo@4");
	pAIL_sequence_user_data = GetProcAddress(hMSS, "_AIL_sequence_user_data@8");
	pAIL_sequence_volume = GetProcAddress(hMSS, "_AIL_sequence_volume@4");
	pAIL_serve = GetProcAddress(hMSS, "_AIL_serve@0");
	pAIL_service_stream = GetProcAddress(hMSS, "_AIL_service_stream@8");
	pAIL_set_3D_distance_factor = GetProcAddress(hMSS, "_AIL_set_3D_distance_factor@8");
	pAIL_set_3D_doppler_factor = GetProcAddress(hMSS, "_AIL_set_3D_doppler_factor@8");
	pAIL_set_3D_orientation = GetProcAddress(hMSS, "_AIL_set_3D_orientation@28");
	pAIL_set_3D_position = GetProcAddress(hMSS, "_AIL_set_3D_position@16");
	pAIL_set_3D_provider_preference = GetProcAddress(hMSS, "_AIL_set_3D_provider_preference@12");
	pAIL_set_3D_rolloff_factor = GetProcAddress(hMSS, "_AIL_set_3D_rolloff_factor@8");
	pAIL_set_3D_room_type = GetProcAddress(hMSS, "_AIL_set_3D_room_type@8");
	pAIL_set_3D_sample_cone = GetProcAddress(hMSS, "_AIL_set_3D_sample_cone@16");
	pAIL_set_3D_sample_distances = GetProcAddress(hMSS, "_AIL_set_3D_sample_distances@12");
	pAIL_set_3D_sample_effects_level = GetProcAddress(hMSS, "_AIL_set_3D_sample_effects_level@8");
	pAIL_set_3D_sample_exclusion = GetProcAddress(hMSS, "_AIL_set_3D_sample_exclusion@8");
	pAIL_set_3D_sample_file = GetProcAddress(hMSS, "_AIL_set_3D_sample_file@8");
	pAIL_set_3D_sample_info = GetProcAddress(hMSS, "_AIL_set_3D_sample_info@8");
	pAIL_set_3D_sample_loop_block = GetProcAddress(hMSS, "_AIL_set_3D_sample_loop_block@12");
	pAIL_set_3D_sample_loop_count = GetProcAddress(hMSS, "_AIL_set_3D_sample_loop_count@8");
	pAIL_set_3D_sample_obstruction = GetProcAddress(hMSS, "_AIL_set_3D_sample_obstruction@8");
	pAIL_set_3D_sample_occlusion = GetProcAddress(hMSS, "_AIL_set_3D_sample_occlusion@8");
	pAIL_set_3D_sample_offset = GetProcAddress(hMSS, "_AIL_set_3D_sample_offset@8");
	pAIL_set_3D_sample_playback_rate = GetProcAddress(hMSS, "_AIL_set_3D_sample_playback_rate@8");
	pAIL_set_3D_sample_preference = GetProcAddress(hMSS, "_AIL_set_3D_sample_preference@12");
	pAIL_set_3D_sample_volume = GetProcAddress(hMSS, "_AIL_set_3D_sample_volume@8");
	pAIL_set_3D_speaker_type = GetProcAddress(hMSS, "_AIL_set_3D_speaker_type@8");
	pAIL_set_3D_user_data = GetProcAddress(hMSS, "_AIL_set_3D_user_data@12");
	pAIL_set_3D_velocity = GetProcAddress(hMSS, "_AIL_set_3D_velocity@20");
	pAIL_set_3D_velocity_vector = GetProcAddress(hMSS, "_AIL_set_3D_velocity_vector@16");
	pAIL_set_DLS_processor = GetProcAddress(hMSS, "_AIL_set_DLS_processor@12");
	pAIL_set_DirectSound_HWND = GetProcAddress(hMSS, "_AIL_set_DirectSound_HWND@8");
	pAIL_set_XMIDI_master_volume = GetProcAddress(hMSS, "_AIL_set_XMIDI_master_volume@8");
	pAIL_set_digital_driver_processor = GetProcAddress(hMSS, "_AIL_set_digital_driver_processor@12");
	pAIL_set_digital_master_reverb = GetProcAddress(hMSS, "_AIL_set_digital_master_reverb@16");
	pAIL_set_digital_master_reverb_levels = GetProcAddress(hMSS, "_AIL_set_digital_master_reverb_levels@12");
	pAIL_set_digital_master_room_type = GetProcAddress(hMSS, "_AIL_set_digital_master_room_type@8");
	pAIL_set_digital_master_volume_level = GetProcAddress(hMSS, "_AIL_set_digital_master_volume_level@8");
	pAIL_set_error = GetProcAddress(hMSS, "_AIL_set_error@4");
	pAIL_set_file_async_callbacks = GetProcAddress(hMSS, "_AIL_set_file_async_callbacks@20");
	pAIL_set_file_callbacks = GetProcAddress(hMSS, "_AIL_set_file_callbacks@16");
	pAIL_set_filter_DLS_preference = GetProcAddress(hMSS, "_AIL_set_filter_DLS_preference@12");
	pAIL_set_filter_preference = GetProcAddress(hMSS, "_AIL_set_filter_preference@12");
	pAIL_set_filter_sample_preference = GetProcAddress(hMSS, "_AIL_set_filter_sample_preference@12");
	pAIL_set_filter_stream_preference = GetProcAddress(hMSS, "_AIL_set_filter_stream_preference@12");
	pAIL_set_input_state = GetProcAddress(hMSS, "_AIL_set_input_state@8");
	pAIL_set_named_sample_file = GetProcAddress(hMSS, "_AIL_set_named_sample_file@20");
	pAIL_set_preference = GetProcAddress(hMSS, "_AIL_set_preference@8");
	pAIL_set_redist_directory = GetProcAddress(hMSS, "_AIL_set_redist_directory@4");
	pAIL_set_sample_address = GetProcAddress(hMSS, "_AIL_set_sample_address@12");
	pAIL_set_sample_adpcm_block_size = GetProcAddress(hMSS, "_AIL_set_sample_adpcm_block_size@8");
	pAIL_set_sample_file = GetProcAddress(hMSS, "_AIL_set_sample_file@12");
	pAIL_set_sample_loop_block = GetProcAddress(hMSS, "_AIL_set_sample_loop_block@12");
	pAIL_set_sample_loop_count = GetProcAddress(hMSS, "_AIL_set_sample_loop_count@8");
	pAIL_set_sample_low_pass_cut_off = GetProcAddress(hMSS, "_AIL_set_sample_low_pass_cut_off@8");
	pAIL_set_sample_ms_position = GetProcAddress(hMSS, "_AIL_set_sample_ms_position@8");
	pAIL_set_sample_playback_rate = GetProcAddress(hMSS, "_AIL_set_sample_playback_rate@8");
	pAIL_set_sample_position = GetProcAddress(hMSS, "_AIL_set_sample_position@8");
	pAIL_set_sample_processor = GetProcAddress(hMSS, "_AIL_set_sample_processor@12");
	pAIL_set_sample_reverb_levels = GetProcAddress(hMSS, "_AIL_set_sample_reverb_levels@12");
	pAIL_set_sample_type = GetProcAddress(hMSS, "_AIL_set_sample_type@12");
	pAIL_set_sample_user_data = GetProcAddress(hMSS, "_AIL_set_sample_user_data@12");
	pAIL_set_sample_volume_levels = GetProcAddress(hMSS, "_AIL_set_sample_volume_levels@12");
	pAIL_set_sample_volume_pan = GetProcAddress(hMSS, "_AIL_set_sample_volume_pan@12");
	pAIL_set_sequence_loop_count = GetProcAddress(hMSS, "_AIL_set_sequence_loop_count@8");
	pAIL_set_sequence_ms_position = GetProcAddress(hMSS, "_AIL_set_sequence_ms_position@8");
	pAIL_set_sequence_tempo = GetProcAddress(hMSS, "_AIL_set_sequence_tempo@12");
	pAIL_set_sequence_user_data = GetProcAddress(hMSS, "_AIL_set_sequence_user_data@12");
	pAIL_set_sequence_volume = GetProcAddress(hMSS, "_AIL_set_sequence_volume@12");
	pAIL_set_stream_loop_block = GetProcAddress(hMSS, "_AIL_set_stream_loop_block@12");
	pAIL_set_stream_loop_count = GetProcAddress(hMSS, "_AIL_set_stream_loop_count@8");
	pAIL_set_stream_low_pass_cut_off = GetProcAddress(hMSS, "_AIL_set_stream_low_pass_cut_off@8");
	pAIL_set_stream_ms_position = GetProcAddress(hMSS, "_AIL_set_stream_ms_position@8");
	pAIL_set_stream_playback_rate = GetProcAddress(hMSS, "_AIL_set_stream_playback_rate@8");
	pAIL_set_stream_position = GetProcAddress(hMSS, "_AIL_set_stream_position@8");
	pAIL_set_stream_processor = GetProcAddress(hMSS, "_AIL_set_stream_processor@12");
	pAIL_set_stream_reverb_levels = GetProcAddress(hMSS, "_AIL_set_stream_reverb_levels@12");
	pAIL_set_stream_user_data = GetProcAddress(hMSS, "_AIL_set_stream_user_data@12");
	pAIL_set_stream_volume_levels = GetProcAddress(hMSS, "_AIL_set_stream_volume_levels@12");
	pAIL_set_stream_volume_pan = GetProcAddress(hMSS, "_AIL_set_stream_volume_pan@12");
	pAIL_set_timer_divisor = GetProcAddress(hMSS, "_AIL_set_timer_divisor@8");
	pAIL_set_timer_frequency = GetProcAddress(hMSS, "_AIL_set_timer_frequency@8");
	pAIL_set_timer_period = GetProcAddress(hMSS, "_AIL_set_timer_period@8");
	pAIL_set_timer_user = GetProcAddress(hMSS, "_AIL_set_timer_user@8");
	pAIL_shutdown = GetProcAddress(hMSS, "_AIL_shutdown@0");
	pAIL_size_processed_digital_audio = GetProcAddress(hMSS, "_AIL_size_processed_digital_audio@16");
	pAIL_start_3D_sample = GetProcAddress(hMSS, "_AIL_start_3D_sample@4");
	pAIL_start_all_timers = GetProcAddress(hMSS, "_AIL_start_all_timers@0");
	pAIL_start_sample = GetProcAddress(hMSS, "_AIL_start_sample@4");
	pAIL_start_sequence = GetProcAddress(hMSS, "_AIL_start_sequence@4");
	pAIL_start_stream = GetProcAddress(hMSS, "_AIL_start_stream@4");
	pAIL_start_timer = GetProcAddress(hMSS, "_AIL_start_timer@4");
	pAIL_startup = GetProcAddress(hMSS, "_AIL_startup@0");
	pAIL_stop_3D_sample = GetProcAddress(hMSS, "_AIL_stop_3D_sample@4");
	pAIL_stop_all_timers = GetProcAddress(hMSS, "_AIL_stop_all_timers@0");
	pAIL_stop_sample = GetProcAddress(hMSS, "_AIL_stop_sample@4");
	pAIL_stop_sequence = GetProcAddress(hMSS, "_AIL_stop_sequence@4");
	pAIL_stop_timer = GetProcAddress(hMSS, "_AIL_stop_timer@4");
	pAIL_stream_info = GetProcAddress(hMSS, "_AIL_stream_info@20");
	pAIL_stream_loop_count = GetProcAddress(hMSS, "_AIL_stream_loop_count@4");
	pAIL_stream_low_pass_cut_off = GetProcAddress(hMSS, "_AIL_stream_low_pass_cut_off@4");
	pAIL_stream_ms_position = GetProcAddress(hMSS, "_AIL_stream_ms_position@12");
	pAIL_stream_playback_rate = GetProcAddress(hMSS, "_AIL_stream_playback_rate@4");
	pAIL_stream_position = GetProcAddress(hMSS, "_AIL_stream_position@4");
	pAIL_stream_reverb_levels = GetProcAddress(hMSS, "_AIL_stream_reverb_levels@12");
	pAIL_stream_status = GetProcAddress(hMSS, "_AIL_stream_status@4");
	pAIL_stream_user_data = GetProcAddress(hMSS, "_AIL_stream_user_data@8");
	pAIL_stream_volume_levels = GetProcAddress(hMSS, "_AIL_stream_volume_levels@12");
	pAIL_stream_volume_pan = GetProcAddress(hMSS, "_AIL_stream_volume_pan@12");
	pAIL_true_sequence_channel = GetProcAddress(hMSS, "_AIL_true_sequence_channel@8");
	pAIL_unlock = GetProcAddress(hMSS, "_AIL_unlock@0");
	pAIL_unlock_mutex = GetProcAddress(hMSS, "_AIL_unlock_mutex@0");
	pAIL_update_3D_position = GetProcAddress(hMSS, "_AIL_update_3D_position@8");
	pAIL_us_count = GetProcAddress(hMSS, "_AIL_us_count@0");
	pAIL_waveOutClose = GetProcAddress(hMSS, "_AIL_waveOutClose@4");
	pAIL_waveOutOpen = GetProcAddress(hMSS, "_AIL_waveOutOpen@16");
	pDLSMSSGetCPU = GetProcAddress(hMSS, "_DLSMSSGetCPU@4");
	pMIX_RIB_MAIN = GetProcAddress(hMSS, "_MIX_RIB_MAIN@8");
	pRIB_enumerate_providers = GetProcAddress(hMSS, "_RIB_enumerate_providers@12");
	pRIB_find_file_dec_provider = GetProcAddress(hMSS, "_RIB_find_file_dec_provider@20");
	pRIB_find_files_provider = GetProcAddress(hMSS, "_RIB_find_files_provider@20");
	pRIB_find_provider = GetProcAddress(hMSS, "_RIB_find_provider@12");
	pRIB_load_application_providers = GetProcAddress(hMSS, "_RIB_load_application_providers@4");
	pRIB_load_static_provider_library = GetProcAddress(hMSS, "_RIB_load_static_provider_library@8");
	pRIB_provider_system_data = GetProcAddress(hMSS, "_RIB_provider_system_data@8");
	pRIB_provider_user_data = GetProcAddress(hMSS, "_RIB_provider_user_data@8");
	pRIB_set_provider_system_data = GetProcAddress(hMSS, "_RIB_set_provider_system_data@12");
	pRIB_set_provider_user_data = GetProcAddress(hMSS, "_RIB_set_provider_user_data@12");
	pstream_background = GetProcAddress(hMSS, "stream_background");

    miles32_loaded = true; 
}

extern "C" __declspec(dllexport) __attribute__((naked))  void AIL_debug_printf() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_debug_printf) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_debug_printf)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void AIL_sprintf() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sprintf) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sprintf)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void DLSClose() {
    // ensure pointers are initialized (cheap check)
    if (!pDLSClose) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pDLSClose)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void DLSCompactMemory() {
    // ensure pointers are initialized (cheap check)
    if (!pDLSCompactMemory) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pDLSCompactMemory)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void DLSGetInfo() {
    // ensure pointers are initialized (cheap check)
    if (!pDLSGetInfo) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pDLSGetInfo)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void DLSLoadFile() {
    // ensure pointers are initialized (cheap check)
    if (!pDLSLoadFile) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pDLSLoadFile)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void DLSLoadMemFile() {
    // ensure pointers are initialized (cheap check)
    if (!pDLSLoadMemFile) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pDLSLoadMemFile)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void DLSMSSOpen() {
    // ensure pointers are initialized (cheap check)
    if (!pDLSMSSOpen) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pDLSMSSOpen)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void DLSSetAttribute() {
    // ensure pointers are initialized (cheap check)
    if (!pDLSSetAttribute) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pDLSSetAttribute)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void DLSUnloadAll() {
    // ensure pointers are initialized (cheap check)
    if (!pDLSUnloadAll) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pDLSUnloadAll)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void DLSUnloadFile() {
    // ensure pointers are initialized (cheap check)
    if (!pDLSUnloadFile) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pDLSUnloadFile)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void RIB_alloc_provider_handle() {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_alloc_provider_handle) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_alloc_provider_handle)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void RIB_enumerate_interface() {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_enumerate_interface) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_enumerate_interface)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void RIB_error() {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_error) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_error)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void RIB_find_file_provider() {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_find_file_provider) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_find_file_provider)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void RIB_free_provider_handle() {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_free_provider_handle) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_free_provider_handle)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void RIB_free_provider_library() {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_free_provider_library) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_free_provider_library)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void RIB_load_provider_library() {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_load_provider_library) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_load_provider_library)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void RIB_register_interface() {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_register_interface) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_register_interface)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void RIB_request_interface() {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_request_interface) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_request_interface)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void RIB_request_interface_entry() {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_request_interface_entry) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_request_interface_entry)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void RIB_type_string() {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_type_string) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_type_string)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked))  void RIB_unregister_interface() {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_unregister_interface) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_unregister_interface)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_distance_factor(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_distance_factor) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_distance_factor)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_doppler_factor(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_doppler_factor) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_doppler_factor)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_orientation(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4, DWORD a5, DWORD a6) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_orientation) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_orientation)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_position(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_provider_attribute(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_provider_attribute) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_provider_attribute)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_rolloff_factor(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_rolloff_factor) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_rolloff_factor)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_room_type(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_room_type) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_room_type)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_attribute(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_attribute) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_attribute)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_cone(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_cone) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_cone)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_distances(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_distances) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_distances)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_effects_level(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_effects_level) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_effects_level)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_exclusion(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_exclusion) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_exclusion)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_length(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_length) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_length)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_loop_count(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_loop_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_loop_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_obstruction(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_obstruction) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_obstruction)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_occlusion(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_occlusion) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_occlusion)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_offset(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_offset) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_offset)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_playback_rate(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_playback_rate) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_playback_rate)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_status(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_status) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_status)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_sample_volume(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_sample_volume) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_sample_volume)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_speaker_type(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_speaker_type) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_speaker_type)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_user_data(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_user_data) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_user_data)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_3D_velocity(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_3D_velocity) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_3D_velocity)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_DLS_close(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_DLS_close) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_DLS_close)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_DLS_compact(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_DLS_compact) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_DLS_compact)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_DLS_get_info(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_DLS_get_info) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_DLS_get_info)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_DLS_get_reverb_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_DLS_get_reverb_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_DLS_get_reverb_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_DLS_load_file(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_DLS_load_file) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_DLS_load_file)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_DLS_load_memory(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_DLS_load_memory) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_DLS_load_memory)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_DLS_open(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4, DWORD a5, DWORD a6) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_DLS_open) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_DLS_open)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_DLS_set_reverb_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_DLS_set_reverb_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_DLS_set_reverb_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_DLS_unload(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_DLS_unload) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_DLS_unload)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_HWND() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_HWND) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_HWND)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_MIDI_handle_reacquire(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_MIDI_handle_reacquire) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_MIDI_handle_reacquire)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_MIDI_handle_release(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_MIDI_handle_release) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_MIDI_handle_release)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_MIDI_to_XMI(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_MIDI_to_XMI) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_MIDI_to_XMI)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_MMX_available() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_MMX_available) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_MMX_available)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_WAV_file_write(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_WAV_file_write) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_WAV_file_write)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_WAV_info(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_WAV_info) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_WAV_info)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_XMIDI_master_volume(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_XMIDI_master_volume) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_XMIDI_master_volume)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_active_3D_sample_count(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_active_3D_sample_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_active_3D_sample_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_active_sample_count(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_active_sample_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_active_sample_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_active_sequence_count(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_active_sequence_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_active_sequence_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_allocate_3D_sample_handle(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_allocate_3D_sample_handle) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_allocate_3D_sample_handle)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_allocate_file_sample(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_allocate_file_sample) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_allocate_file_sample)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_allocate_sample_handle(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_allocate_sample_handle) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_allocate_sample_handle)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_allocate_sequence_handle(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_allocate_sequence_handle) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_allocate_sequence_handle)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_auto_service_stream(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_auto_service_stream) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_auto_service_stream)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_auto_update_3D_position(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_auto_update_3D_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_auto_update_3D_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_background() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_background) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_background)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_branch_index(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_branch_index) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_branch_index)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_channel_notes(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_channel_notes) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_channel_notes)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_close_3D_listener(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_close_3D_listener) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_close_3D_listener)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_close_3D_object(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_close_3D_object) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_close_3D_object)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_close_3D_provider(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_close_3D_provider) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_close_3D_provider)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_close_XMIDI_driver(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_close_XMIDI_driver) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_close_XMIDI_driver)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_close_digital_driver(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_close_digital_driver) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_close_digital_driver)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_close_filter(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_close_filter) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_close_filter)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_close_input(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_close_input) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_close_input)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_close_stream(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_close_stream) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_close_stream)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_compress_ADPCM(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_compress_ADPCM) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_compress_ADPCM)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_compress_ASI(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_compress_ASI) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_compress_ASI)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_compress_DLS(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_compress_DLS) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_compress_DLS)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_controller_value(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_controller_value) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_controller_value)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_create_wave_synthesizer(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_create_wave_synthesizer) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_create_wave_synthesizer)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_decompress_ADPCM(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_decompress_ADPCM) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_decompress_ADPCM)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_decompress_ASI(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4, DWORD a5) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_decompress_ASI) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_decompress_ASI)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_delay(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_delay) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_delay)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_destroy_wave_synthesizer(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_destroy_wave_synthesizer) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_destroy_wave_synthesizer)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_digital_CPU_percent(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_digital_CPU_percent) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_digital_CPU_percent)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_digital_configuration(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_digital_configuration) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_digital_configuration)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_digital_handle_reacquire(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_digital_handle_reacquire) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_digital_handle_reacquire)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_digital_handle_release(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_digital_handle_release) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_digital_handle_release)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_digital_latency(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_digital_latency) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_digital_latency)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_digital_master_reverb(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_digital_master_reverb) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_digital_master_reverb)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_digital_master_reverb_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_digital_master_reverb_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_digital_master_reverb_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_digital_master_volume_level(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_digital_master_volume_level) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_digital_master_volume_level)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_end_3D_sample(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_end_3D_sample) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_end_3D_sample)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_end_sample(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_end_sample) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_end_sample)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_end_sequence(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_end_sequence) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_end_sequence)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_enumerate_3D_provider_attributes(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_enumerate_3D_provider_attributes) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_enumerate_3D_provider_attributes)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_enumerate_3D_providers(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_enumerate_3D_providers) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_enumerate_3D_providers)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_enumerate_3D_sample_attributes(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_enumerate_3D_sample_attributes) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_enumerate_3D_sample_attributes)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_enumerate_filter_attributes(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_enumerate_filter_attributes) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_enumerate_filter_attributes)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_enumerate_filter_sample_attributes(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_enumerate_filter_sample_attributes) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_enumerate_filter_sample_attributes)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_enumerate_filters(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_enumerate_filters) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_enumerate_filters)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_extract_DLS(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4, DWORD a5, DWORD a6) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_extract_DLS) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_extract_DLS)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_file_error() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_file_error) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_file_error)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_file_read(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_file_read) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_file_read)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_file_size(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_file_size) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_file_size)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_file_type(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_file_type) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_file_type)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_file_write(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_file_write) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_file_write)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_filter_DLS_attribute(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_filter_DLS_attribute) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_filter_DLS_attribute)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_filter_DLS_with_XMI(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4, DWORD a5) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_filter_DLS_with_XMI) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_filter_DLS_with_XMI)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_filter_attribute(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_filter_attribute) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_filter_attribute)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_filter_sample_attribute(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_filter_sample_attribute) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_filter_sample_attribute)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_filter_stream_attribute(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_filter_stream_attribute) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_filter_stream_attribute)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_find_DLS(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4, DWORD a5) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_find_DLS) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_find_DLS)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_get_DirectSound_info(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_get_DirectSound_info) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_get_DirectSound_info)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_get_input_info(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_get_input_info) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_get_input_info)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_get_preference(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_get_preference) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_get_preference)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_get_timer_highest_delay() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_get_timer_highest_delay) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_get_timer_highest_delay)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_init_sample(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_init_sample) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_init_sample)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_init_sequence(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_init_sequence) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_init_sequence)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_last_error() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_last_error) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_last_error)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_list_DLS(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_list_DLS) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_list_DLS)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_list_MIDI(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_list_MIDI) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_list_MIDI)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_load_sample_buffer(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_load_sample_buffer) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_load_sample_buffer)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_lock() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_lock) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_lock)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_lock_channel(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_lock_channel) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_lock_channel)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_lock_mutex() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_lock_mutex) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_lock_mutex)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_map_sequence_channel(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_map_sequence_channel) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_map_sequence_channel)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_mem_alloc_lock(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_mem_alloc_lock) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_mem_alloc_lock)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_mem_free_lock(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_mem_free_lock) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_mem_free_lock)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_mem_use_free(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_mem_use_free) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_mem_use_free)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_mem_use_malloc(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_mem_use_malloc) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_mem_use_malloc)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_merge_DLS_with_XMI(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_merge_DLS_with_XMI) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_merge_DLS_with_XMI)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_midiOutClose(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_midiOutClose) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_midiOutClose)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_midiOutOpen(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_midiOutOpen) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_midiOutOpen)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_minimum_sample_buffer_size(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_minimum_sample_buffer_size) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_minimum_sample_buffer_size)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_ms_count() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_ms_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_ms_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_open_3D_listener(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_open_3D_listener) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_open_3D_listener)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_open_3D_object(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_open_3D_object) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_open_3D_object)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_open_3D_provider(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_open_3D_provider) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_open_3D_provider)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_open_XMIDI_driver(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_open_XMIDI_driver) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_open_XMIDI_driver)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_open_digital_driver(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_open_digital_driver) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_open_digital_driver)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_open_filter(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_open_filter) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_open_filter)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_open_input(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_open_input) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_open_input)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_open_stream(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_open_stream) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_open_stream)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_pause_stream(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_pause_stream) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_pause_stream)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_primary_digital_driver(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_primary_digital_driver) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_primary_digital_driver)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_process_digital_audio(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4, DWORD a5) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_process_digital_audio) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_process_digital_audio)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_copy(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_copy) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_copy)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_halt(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_halt) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_halt)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_handles(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_handles) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_handles)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_load(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_load) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_load)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_load_and_play(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_load_and_play) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_load_and_play)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_load_mem(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_load_mem) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_load_mem)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_ms_length(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_ms_length) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_ms_length)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_ms_position(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_ms_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_ms_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_play(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_play) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_play)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_set_low_pass_cut_off(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_set_low_pass_cut_off) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_set_low_pass_cut_off)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_set_ms_position(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_set_ms_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_set_ms_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_set_reverb_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_set_reverb_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_set_reverb_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_set_speed(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_set_speed) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_set_speed)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_set_volume(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_set_volume) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_set_volume)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_shutdown() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_shutdown) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_shutdown)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_startup(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_startup) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_startup)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_status(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_status) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_status)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_type(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_type) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_type)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_quick_unload(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_quick_unload) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_quick_unload)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_close(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_close) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_close)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_eject(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_eject) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_eject)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_id(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_id) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_id)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_open(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_open) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_open)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_open_drive(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_open_drive) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_open_drive)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_pause(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_pause) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_pause)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_play(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_play) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_play)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_position(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_resume(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_resume) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_resume)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_retract(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_retract) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_retract)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_set_volume_level(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_set_volume_level) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_set_volume_level)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_status(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_status) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_status)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_stop(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_stop) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_stop)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_track(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_track) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_track)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_track_info(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_track_info) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_track_info)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_tracks(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_tracks) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_tracks)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_redbook_volume_level(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_redbook_volume_level) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_redbook_volume_level)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_3D_EOS_callback(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_3D_EOS_callback) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_3D_EOS_callback)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_EOB_callback(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_EOB_callback) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_EOB_callback)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_EOF_callback(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_EOF_callback) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_EOF_callback)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_EOS_callback(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_EOS_callback) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_EOS_callback)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_ICA_array(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_ICA_array) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_ICA_array)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_SOB_callback(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_SOB_callback) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_SOB_callback)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_beat_callback(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_beat_callback) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_beat_callback)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_event_callback(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_event_callback) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_event_callback)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_prefix_callback(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_prefix_callback) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_prefix_callback)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_sequence_callback(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_sequence_callback) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_sequence_callback)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_stream_callback(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_stream_callback) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_stream_callback)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_timbre_callback(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_timbre_callback) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_timbre_callback)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_timer(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_timer) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_timer)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_register_trigger_callback(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_register_trigger_callback) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_register_trigger_callback)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_release_3D_sample_handle(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_release_3D_sample_handle) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_release_3D_sample_handle)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_release_all_timers() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_release_all_timers) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_release_all_timers)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_release_channel(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_release_channel) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_release_channel)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_release_sample_handle(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_release_sample_handle) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_release_sample_handle)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_release_sequence_handle(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_release_sequence_handle) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_release_sequence_handle)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_release_timer_handle(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_release_timer_handle) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_release_timer_handle)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_request_EOB_ASI_reset(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_request_EOB_ASI_reset) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_request_EOB_ASI_reset)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_resume_3D_sample(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_resume_3D_sample) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_resume_3D_sample)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_resume_sample(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_resume_sample) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_resume_sample)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_resume_sequence(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_resume_sequence) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_resume_sequence)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_buffer_info(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_buffer_info) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_buffer_info)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_buffer_ready(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_buffer_ready) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_buffer_ready)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_granularity(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_granularity) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_granularity)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_loop_count(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_loop_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_loop_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_low_pass_cut_off(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_low_pass_cut_off) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_low_pass_cut_off)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_ms_position(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_ms_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_ms_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_playback_rate(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_playback_rate) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_playback_rate)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_position(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_reverb_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_reverb_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_reverb_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_status(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_status) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_status)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_user_data(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_user_data) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_user_data)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_volume_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_volume_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_volume_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sample_volume_pan(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sample_volume_pan) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sample_volume_pan)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_send_channel_voice_message(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_send_channel_voice_message) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_send_channel_voice_message)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_send_sysex_message(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_send_sysex_message) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_send_sysex_message)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sequence_loop_count(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sequence_loop_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sequence_loop_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sequence_ms_position(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sequence_ms_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sequence_ms_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sequence_position(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sequence_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sequence_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sequence_status(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sequence_status) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sequence_status)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sequence_tempo(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sequence_tempo) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sequence_tempo)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sequence_user_data(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sequence_user_data) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sequence_user_data)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_sequence_volume(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_sequence_volume) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_sequence_volume)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_serve() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_serve) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_serve)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_service_stream(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_service_stream) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_service_stream)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_distance_factor(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_distance_factor) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_distance_factor)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_doppler_factor(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_doppler_factor) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_doppler_factor)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_orientation(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4, DWORD a5, DWORD a6) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_orientation) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_orientation)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_position(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_provider_preference(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_provider_preference) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_provider_preference)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_rolloff_factor(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_rolloff_factor) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_rolloff_factor)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_room_type(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_room_type) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_room_type)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_cone(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_cone) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_cone)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_distances(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_distances) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_distances)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_effects_level(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_effects_level) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_effects_level)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_exclusion(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_exclusion) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_exclusion)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_file(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_file) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_file)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_info(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_info) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_info)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_loop_block(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_loop_block) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_loop_block)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_loop_count(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_loop_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_loop_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_obstruction(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_obstruction) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_obstruction)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_occlusion(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_occlusion) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_occlusion)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_offset(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_offset) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_offset)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_playback_rate(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_playback_rate) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_playback_rate)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_preference(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_preference) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_preference)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_sample_volume(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_sample_volume) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_sample_volume)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_speaker_type(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_speaker_type) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_speaker_type)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_user_data(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_user_data) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_user_data)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_velocity(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_velocity) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_velocity)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_3D_velocity_vector(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_3D_velocity_vector) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_3D_velocity_vector)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_DLS_processor(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_DLS_processor) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_DLS_processor)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_DirectSound_HWND(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_DirectSound_HWND) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_DirectSound_HWND)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_XMIDI_master_volume(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_XMIDI_master_volume) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_XMIDI_master_volume)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_digital_driver_processor(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_digital_driver_processor) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_digital_driver_processor)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_digital_master_reverb(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_digital_master_reverb) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_digital_master_reverb)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_digital_master_reverb_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_digital_master_reverb_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_digital_master_reverb_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_digital_master_room_type(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_digital_master_room_type) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_digital_master_room_type)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_digital_master_volume_level(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_digital_master_volume_level) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_digital_master_volume_level)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_error(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_error) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_error)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_file_async_callbacks(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_file_async_callbacks) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_file_async_callbacks)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_file_callbacks(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_file_callbacks) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_file_callbacks)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_filter_DLS_preference(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_filter_DLS_preference) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_filter_DLS_preference)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_filter_preference(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_filter_preference) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_filter_preference)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_filter_sample_preference(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_filter_sample_preference) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_filter_sample_preference)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_filter_stream_preference(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_filter_stream_preference) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_filter_stream_preference)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_input_state(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_input_state) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_input_state)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_named_sample_file(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_named_sample_file) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_named_sample_file)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_preference(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_preference) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_preference)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_redist_directory(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_redist_directory) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_redist_directory)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_address(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_address) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_address)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_adpcm_block_size(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_adpcm_block_size) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_adpcm_block_size)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_file(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_file) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_file)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_loop_block(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_loop_block) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_loop_block)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_loop_count(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_loop_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_loop_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_low_pass_cut_off(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_low_pass_cut_off) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_low_pass_cut_off)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_ms_position(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_ms_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_ms_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_playback_rate(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_playback_rate) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_playback_rate)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_position(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_processor(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_processor) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_processor)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_reverb_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_reverb_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_reverb_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_type(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_type) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_type)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_user_data(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_user_data) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_user_data)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_volume_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_volume_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_volume_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sample_volume_pan(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sample_volume_pan) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sample_volume_pan)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sequence_loop_count(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sequence_loop_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sequence_loop_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sequence_ms_position(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sequence_ms_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sequence_ms_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sequence_tempo(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sequence_tempo) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sequence_tempo)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sequence_user_data(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sequence_user_data) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sequence_user_data)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_sequence_volume(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_sequence_volume) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_sequence_volume)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_stream_loop_block(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_stream_loop_block) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_stream_loop_block)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_stream_loop_count(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_stream_loop_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_stream_loop_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_stream_low_pass_cut_off(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_stream_low_pass_cut_off) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_stream_low_pass_cut_off)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_stream_ms_position(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_stream_ms_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_stream_ms_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_stream_playback_rate(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_stream_playback_rate) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_stream_playback_rate)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_stream_position(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_stream_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_stream_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_stream_processor(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_stream_processor) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_stream_processor)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_stream_reverb_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_stream_reverb_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_stream_reverb_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_stream_user_data(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_stream_user_data) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_stream_user_data)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_stream_volume_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_stream_volume_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_stream_volume_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_stream_volume_pan(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_stream_volume_pan) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_stream_volume_pan)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_timer_divisor(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_timer_divisor) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_timer_divisor)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_timer_frequency(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_timer_frequency) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_timer_frequency)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_timer_period(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_timer_period) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_timer_period)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_set_timer_user(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_set_timer_user) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_set_timer_user)
    );
}

extern "C" __declspec(dllexport) WINAPI  void _AIL_shutdown() {
    // ensure pointers are initialized (cheap check)
    // lol i had error because of attribute naked 
    if (!pAIL_shutdown) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    void(WINAPI*o)() = (void(WINAPI*)())pAIL_shutdown;
		o();
		extern bool bClosing;
		if (!bClosing)
			return;

		void MSS32_Unload();
		MSS32_Unload();
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_size_processed_digital_audio(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_size_processed_digital_audio) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_size_processed_digital_audio)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI void _AIL_start_3D_sample(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_start_3D_sample) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_start_3D_sample)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_start_all_timers() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_start_all_timers) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_start_all_timers)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_start_sample(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_start_sample) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_start_sample)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_start_sequence(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_start_sequence) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_start_sequence)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_start_stream(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_start_stream) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_start_stream)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_start_timer(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_start_timer) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_start_timer)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_startup() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_startup) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_startup)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stop_3D_sample(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stop_3D_sample) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stop_3D_sample)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stop_all_timers() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stop_all_timers) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stop_all_timers)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stop_sample(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stop_sample) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stop_sample)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stop_sequence(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stop_sequence) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stop_sequence)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stop_timer(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stop_timer) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stop_timer)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stream_info(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stream_info) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stream_info)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stream_loop_count(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stream_loop_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stream_loop_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stream_low_pass_cut_off(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stream_low_pass_cut_off) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stream_low_pass_cut_off)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stream_ms_position(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stream_ms_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stream_ms_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stream_playback_rate(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stream_playback_rate) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stream_playback_rate)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stream_position(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stream_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stream_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stream_reverb_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stream_reverb_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stream_reverb_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stream_status(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stream_status) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stream_status)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stream_user_data(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stream_user_data) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stream_user_data)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stream_volume_levels(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stream_volume_levels) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stream_volume_levels)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_stream_volume_pan(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_stream_volume_pan) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_stream_volume_pan)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_true_sequence_channel(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_true_sequence_channel) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_true_sequence_channel)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_unlock() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_unlock) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_unlock)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_unlock_mutex() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_unlock_mutex) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_unlock_mutex)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_update_3D_position(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_update_3D_position) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_update_3D_position)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_us_count() {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_us_count) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_us_count)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_waveOutClose(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_waveOutClose) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_waveOutClose)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _AIL_waveOutOpen(DWORD a0, DWORD a1, DWORD a2, DWORD a3) {
    // ensure pointers are initialized (cheap check)
    if (!pAIL_waveOutOpen) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pAIL_waveOutOpen)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _DLSMSSGetCPU(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pDLSMSSGetCPU) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pDLSMSSGetCPU)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _MIX_RIB_MAIN(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pMIX_RIB_MAIN) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pMIX_RIB_MAIN)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _RIB_enumerate_providers(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_enumerate_providers) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_enumerate_providers)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _RIB_find_file_dec_provider(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_find_file_dec_provider) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_find_file_dec_provider)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _RIB_find_files_provider(DWORD a0, DWORD a1, DWORD a2, DWORD a3, DWORD a4) {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_find_files_provider) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_find_files_provider)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _RIB_find_provider(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_find_provider) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_find_provider)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _RIB_load_application_providers(DWORD a0) {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_load_application_providers) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_load_application_providers)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _RIB_load_static_provider_library(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_load_static_provider_library) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_load_static_provider_library)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _RIB_provider_system_data(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_provider_system_data) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_provider_system_data)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _RIB_provider_user_data(DWORD a0, DWORD a1) {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_provider_user_data) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_provider_user_data)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _RIB_set_provider_system_data(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_set_provider_system_data) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_set_provider_system_data)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) WINAPI  void _RIB_set_provider_user_data(DWORD a0, DWORD a1, DWORD a2) {
    // ensure pointers are initialized (cheap check)
    if (!pRIB_set_provider_user_data) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pRIB_set_provider_user_data)
    );
}

extern "C" __declspec(dllexport) __attribute__((naked)) void stream_background() {
    // ensure pointers are initialized (cheap check)
    if (!pstream_background) MessageBoxA(NULL, __func__, "CoD: Risen Arena Error", MB_OK | MB_ICONERROR);
    __asm__ volatile (
        "jmp *%0"
        :
        : "r"(pstream_background)
    );
}