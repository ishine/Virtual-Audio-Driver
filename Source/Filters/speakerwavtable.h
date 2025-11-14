/*++

Copyright (c) Microsoft Corporation All Rights Reserved

Module Name:

    speakerwavtable.h

Abstract:

    Declaration of wave miniport tables for the render endpoints.
--*/

#ifndef _VIRTUALAUDIODRIVER_SPEAKERWAVTABLE_H_
#define _VIRTUALAUDIODRIVER_SPEAKERWAVTABLE_H_

//=============================================================================
// Comprehensive audio format support:
// - Bit depths: 8-bit, 16-bit, 24-bit, 32-bit PCM, and 32-bit IEEE Float
// - Sample rates: 8000 Hz to 384000 Hz (all common rates)
// - Channels: Stereo (2), 5.1 Surround (6), and 7.1 Surround (8 channels)
//
#define SPEAKER_DEVICE_MAX_CHANNELS         8    // Max Channels (supports up to 7.1).

#define SPEAKER_HOST_MAX_CHANNELS           8    // Max Channels (supports up to 7.1).

//
// Change bits-per-sample range:
//
#define SPEAKER_HOST_MIN_BITS_PER_SAMPLE    8
#define SPEAKER_HOST_MAX_BITS_PER_SAMPLE    32

//
// Change sample-rate range:
//
#define SPEAKER_HOST_MIN_SAMPLE_RATE        8000
#define SPEAKER_HOST_MAX_SAMPLE_RATE        384000

//
// Max # of pin instances.
//
#define SPEAKER_MAX_INPUT_SYSTEM_STREAMS    1

//=============================================================================
//
// We now list multiple device formats: one for 16-bit and one for 24-bit.
//
// Note: Even though each entry below shows 48kHz as nSamplesPerSec, the
//       data-range below (SpeakerPinDataRangesStream) will expose 
//       48kHz through 192kHz to Windows. Each of these formats can 
//       be validated dynamically within those ranges.
//
static
KSDATAFORMAT_WAVEFORMATEXTENSIBLE SpeakerHostPinSupportedDeviceFormats[] =
{
    //-------------------------------------------------
    // 0) 16-bit, Stereo, 48 kHz (DVD Quality)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0,
            0,
            0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,                  // wFormatTag
                2,                                       // nChannels
                48000,                                   // nSamplesPerSec
                48000 * 2 * 16 / 8,                      // nAvgBytesPerSec
                2 * 16 / 8,                              // nBlockAlign
                16,                                      // wBitsPerSample
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,                                         // wValidBitsPerSample
            KSAUDIO_SPEAKER_STEREO,                     // dwChannelMask
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 1) 24-bit, Stereo, 48 kHz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0,
            0,
            0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                48000,
                48000 * 2 * 24 / 8,                      // nAvgBytesPerSec
                2 * 24 / 8,                              // nBlockAlign
                24,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            24,                                         // wValidBitsPerSample
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 2) 8-bit, Stereo, 8000 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                8000,
                8000 * 2 * 8 / 8,   // nAvgBytesPerSec = 8000 * 2 * 1
                2 * 8 / 8,         // nBlockAlign     = 2 * 1
                8,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            8,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 3) 8-bit, Stereo, 11025 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                11025,
                11025 * 2 * 8 / 8,
                2 * 8 / 8,
                8,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            8,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 4) 16-bit, Stereo, 11025 Hz (Dictation)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                11025,
                11025 * 2 * 16 / 8,
                2 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 5) 16-bit, Stereo, 16000 Hz (Tape Recorder)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                16000,
                16000 * 2 * 16 / 8,
                2 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 6) 16-bit, Stereo, 22050 Hz (AM Radio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                22050,
                22050 * 2 * 16 / 8,
                2 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 7) 16-bit, Stereo, 32000 Hz (FM Radio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                32000,
                32000 * 2 * 16 / 8,
                2 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 8) 16-bit, Stereo, 44100 Hz (CD Quality)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                44100,
                44100 * 2 * 16 / 8,
                2 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 9) 16-bit, Stereo, 88200 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                88200,
                88200 * 2 * 16 / 8,
                2 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 10) 16-bit, Stereo, 96000 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                96000,
                96000 * 2 * 16 / 8,
                2 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 11) 16-bit, Stereo, 176400 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                176400,
                176400 * 2 * 16 / 8,
                2 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 12) 16-bit, Stereo, 192000 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                192000,
                192000 * 2 * 16 / 8,
                2 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 13) 24-bit, Stereo, 44100 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                44100,
                44100 * 2 * 24 / 8,
                2 * 24 / 8,
                24,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            24,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 14) 24-bit, Stereo, 88200 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                88200,
                88200 * 2 * 24 / 8,
                2 * 24 / 8,
                24,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            24,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 15) 24-bit, Stereo, 96000 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                96000,
                96000 * 2 * 24 / 8,
                2 * 24 / 8,
                24,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            24,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 16) 24-bit, Stereo, 176400 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                176400,
                176400 * 2 * 24 / 8,
                2 * 24 / 8,
                24,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            24,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 17) 24-bit, Stereo, 192000 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                192000,
                192000 * 2 * 24 / 8,
                2 * 24 / 8,
                24,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            24,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 18) 32-bit, Stereo, 44100 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                44100,
                44100 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 19) 32-bit, Stereo, 48000 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                48000,
                48000 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 20) 32-bit, Stereo, 88200 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                88200,
                88200 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 21) 32-bit, Stereo, 96000 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                96000,
                96000 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 22) 32-bit, Stereo, 176400 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                176400,
                176400 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 23) 32-bit, Stereo, 192000 Hz (Studio)
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                192000,
                192000 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 24) 8-bit, Stereo, 16000 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                16000,
                16000 * 2 * 8 / 8,
                2 * 8 / 8,
                8,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            8,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 25) 8-bit, Stereo, 22050 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                22050,
                22050 * 2 * 8 / 8,
                2 * 8 / 8,
                8,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            8,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 26) 8-bit, Stereo, 32000 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                32000,
                32000 * 2 * 8 / 8,
                2 * 8 / 8,
                8,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            8,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 27) 8-bit, Stereo, 44100 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                44100,
                44100 * 2 * 8 / 8,
                2 * 8 / 8,
                8,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            8,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 28) 8-bit, Stereo, 48000 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                48000,
                48000 * 2 * 8 / 8,
                2 * 8 / 8,
                8,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            8,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 29) 32-bit, Stereo, 8000 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                8000,
                8000 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 30) 32-bit, Stereo, 11025 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                11025,
                11025 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 31) 32-bit, Stereo, 16000 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                16000,
                16000 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 32) 32-bit, Stereo, 22050 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                22050,
                22050 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 33) 32-bit, Stereo, 32000 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                32000,
                32000 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 34) 32-bit, Stereo, 96000 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                96000,
                96000 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 35) 32-bit, Stereo, 176400 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                176400,
                176400 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // 36) 32-bit IEEE Float, Stereo, 44100 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                44100,
                44100 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT)
        }
    },

    //-------------------------------------------------
    // 37) 32-bit IEEE Float, Stereo, 48000 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                48000,
                48000 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT)
        }
    },

    //-------------------------------------------------
    // 38) 32-bit IEEE Float, Stereo, 96000 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                96000,
                96000 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT)
        }
    },

    //-------------------------------------------------
    // 39) 32-bit IEEE Float, Stereo, 192000 Hz
    //-------------------------------------------------
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                2,
                192000,
                192000 * 2 * 32 / 8,
                2 * 32 / 8,
                32,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            32,
            KSAUDIO_SPEAKER_STEREO,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT)
        }
    },

    //-------------------------------------------------
    // Multi-channel formats (5.1 Surround Sound)
    //-------------------------------------------------
    // 40) 16-bit, 5.1 Surround, 48000 Hz
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                6,                                      // 5.1 = 6 channels
                48000,
                48000 * 6 * 16 / 8,
                6 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_5POINT1,                    // 5.1 channel mask
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    // 41) 24-bit, 5.1 Surround, 48000 Hz
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                6,
                48000,
                48000 * 6 * 24 / 8,
                6 * 24 / 8,
                24,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            24,
            KSAUDIO_SPEAKER_5POINT1,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    // 42) 16-bit, 5.1 Surround, 96000 Hz
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                6,
                96000,
                96000 * 6 * 16 / 8,
                6 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_5POINT1,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    // 43) 24-bit, 5.1 Surround, 96000 Hz
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                6,
                96000,
                96000 * 6 * 24 / 8,
                6 * 24 / 8,
                24,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            24,
            KSAUDIO_SPEAKER_5POINT1,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    //-------------------------------------------------
    // Multi-channel formats (7.1 Surround Sound)
    //-------------------------------------------------
    // 44) 16-bit, 7.1 Surround, 48000 Hz
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                8,                                      // 7.1 = 8 channels
                48000,
                48000 * 8 * 16 / 8,
                8 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_7POINT1,                    // 7.1 channel mask
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    // 45) 24-bit, 7.1 Surround, 48000 Hz
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                8,
                48000,
                48000 * 8 * 24 / 8,
                8 * 24 / 8,
                24,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            24,
            KSAUDIO_SPEAKER_7POINT1,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    // 46) 16-bit, 7.1 Surround, 96000 Hz
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                8,
                96000,
                96000 * 8 * 16 / 8,
                8 * 16 / 8,
                16,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            16,
            KSAUDIO_SPEAKER_7POINT1,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    },

    // 47) 24-bit, 7.1 Surround, 96000 Hz
    {
        {
            sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
            0, 0, 0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },
        {
            {
                WAVE_FORMAT_EXTENSIBLE,
                8,
                96000,
                96000 * 8 * 24 / 8,
                8 * 24 / 8,
                24,
                sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
            },
            24,
            KSAUDIO_SPEAKER_7POINT1,
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
        }
    }
};


//
// Supported modes (only on streaming pins).
// Here we pick one as default, but you could list more.
//
//
// Supported modes (only on streaming pins).
// Here we pick multiple entries for demonstration, each referencing
// a different format from SpeakerHostPinSupportedDeviceFormats[].
//
static
MODE_AND_DEFAULT_FORMAT SpeakerHostPinSupportedDeviceModes[] =
{
    // 0) 16-bit, Stereo, 48000 Hz (DVD Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[0].DataFormat
    },

    // 1) 24-bit, Stereo, 48000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[1].DataFormat
    },

    // 2) 8-bit, Stereo, 8000 Hz (Lowest Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[2].DataFormat
    },

    // 3) 8-bit, Stereo, 11025 Hz (Telephone Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[3].DataFormat
    },

    // 4) 16-bit, Stereo, 11025 Hz (Dictation Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[4].DataFormat
    },

    // 5) 16-bit, Stereo, 16000 Hz (Tape Recorder Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[5].DataFormat
    },

    // 6) 16-bit, Stereo, 22050 Hz (AM Radio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[6].DataFormat
    },

    // 7) 16-bit, Stereo, 32000 Hz (FM Radio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[7].DataFormat
    },

    // 8) 16-bit, Stereo, 44100 Hz (CD Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[8].DataFormat
    },

    // 9) 16-bit, Stereo, 88200 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[9].DataFormat
    },

    // 10) 16-bit, Stereo, 96000 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[10].DataFormat
    },

    // 11) 16-bit, Stereo, 176400 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[11].DataFormat
    },

    // 12) 16-bit, Stereo, 192000 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[12].DataFormat
    },

    // 13) 24-bit, Stereo, 44100 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[13].DataFormat
    },

    // 14) 24-bit, Stereo, 88200 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[14].DataFormat
    },

    // 15) 24-bit, Stereo, 96000 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[15].DataFormat
    },

    // 16) 24-bit, Stereo, 176400 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[16].DataFormat
    },

    // 17) 24-bit, Stereo, 192000 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[17].DataFormat
    },

    // 18) 32-bit, Stereo, 44100 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[18].DataFormat
    },

    // 19) 32-bit, Stereo, 48000 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[19].DataFormat
    },

    // 20) 32-bit, Stereo, 88200 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[20].DataFormat
    },

    // 21) 32-bit, Stereo, 96000 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[21].DataFormat
    },

    // 22) 32-bit, Stereo, 176400 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[22].DataFormat
    },

    // 23) 32-bit, Stereo, 192000 Hz (Studio Quality)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[23].DataFormat
    },

    // 24) 8-bit, Stereo, 16000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[24].DataFormat
    },

    // 25) 8-bit, Stereo, 22050 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[25].DataFormat
    },

    // 26) 8-bit, Stereo, 32000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[26].DataFormat
    },

    // 27) 8-bit, Stereo, 44100 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[27].DataFormat
    },

    // 28) 8-bit, Stereo, 48000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[28].DataFormat
    },

    // 29) 32-bit, Stereo, 8000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[29].DataFormat
    },

    // 30) 32-bit, Stereo, 11025 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[30].DataFormat
    },

    // 31) 32-bit, Stereo, 16000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[31].DataFormat
    },

    // 32) 32-bit, Stereo, 22050 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[32].DataFormat
    },

    // 33) 32-bit, Stereo, 32000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[33].DataFormat
    },

    // 34) 32-bit, Stereo, 96000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[34].DataFormat
    },

    // 35) 32-bit, Stereo, 176400 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[35].DataFormat
    },

    // 36) 32-bit IEEE Float, Stereo, 44100 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[36].DataFormat
    },

    // 37) 32-bit IEEE Float, Stereo, 48000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[37].DataFormat
    },

    // 38) 32-bit IEEE Float, Stereo, 96000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[38].DataFormat
    },

    // 39) 32-bit IEEE Float, Stereo, 192000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[39].DataFormat
    },

    //-------------------------------------------------
    // Multi-channel formats (5.1 and 7.1) in DEFAULT mode
    //-------------------------------------------------
    // 40) 16-bit, 5.1 Surround, 48000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[40].DataFormat
    },

    // 41) 24-bit, 5.1 Surround, 48000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[41].DataFormat
    },

    // 42) 16-bit, 5.1 Surround, 96000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[42].DataFormat
    },

    // 43) 24-bit, 5.1 Surround, 96000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[43].DataFormat
    },

    // 44) 16-bit, 7.1 Surround, 48000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[44].DataFormat
    },

    // 45) 24-bit, 7.1 Surround, 48000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[45].DataFormat
    },

    // 46) 16-bit, 7.1 Surround, 96000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[46].DataFormat
    },

    // 47) 24-bit, 7.1 Surround, 96000 Hz
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &SpeakerHostPinSupportedDeviceFormats[47].DataFormat
    },

    //-------------------------------------------------
    // COMMUNICATIONS mode - optimized for voice calls
    //-------------------------------------------------
    // 48) 16-bit, Stereo, 48000 Hz (COMMUNICATIONS)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_COMMUNICATIONS,
        &SpeakerHostPinSupportedDeviceFormats[0].DataFormat
    },

    // 49) 16-bit, Stereo, 44100 Hz (COMMUNICATIONS)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_COMMUNICATIONS,
        &SpeakerHostPinSupportedDeviceFormats[8].DataFormat
    },

    //-------------------------------------------------
    // SPEECH mode - optimized for speech recognition
    //-------------------------------------------------
    // 50) 16-bit, Stereo, 16000 Hz (SPEECH)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_SPEECH,
        &SpeakerHostPinSupportedDeviceFormats[5].DataFormat
    },

    // 51) 16-bit, Stereo, 48000 Hz (SPEECH)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_SPEECH,
        &SpeakerHostPinSupportedDeviceFormats[0].DataFormat
    },

    //-------------------------------------------------
    // MEDIA mode - optimized for media playback
    //-------------------------------------------------
    // 52) 16-bit, Stereo, 44100 Hz (MEDIA)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_MEDIA,
        &SpeakerHostPinSupportedDeviceFormats[8].DataFormat
    },

    // 53) 24-bit, Stereo, 48000 Hz (MEDIA)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_MEDIA,
        &SpeakerHostPinSupportedDeviceFormats[1].DataFormat
    },

    // 54) 16-bit, Stereo, 96000 Hz (MEDIA)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_MEDIA,
        &SpeakerHostPinSupportedDeviceFormats[10].DataFormat
    },

    // 55) 24-bit, Stereo, 96000 Hz (MEDIA)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_MEDIA,
        &SpeakerHostPinSupportedDeviceFormats[15].DataFormat
    },

    // 56) 16-bit, 5.1 Surround, 48000 Hz (MEDIA)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_MEDIA,
        &SpeakerHostPinSupportedDeviceFormats[40].DataFormat
    },

    // 57) 24-bit, 5.1 Surround, 48000 Hz (MEDIA)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_MEDIA,
        &SpeakerHostPinSupportedDeviceFormats[41].DataFormat
    },

    // 58) 16-bit, 7.1 Surround, 48000 Hz (MEDIA)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_MEDIA,
        &SpeakerHostPinSupportedDeviceFormats[44].DataFormat
    },

    // 59) 24-bit, 7.1 Surround, 48000 Hz (MEDIA)
    {
        STATIC_AUDIO_SIGNALPROCESSINGMODE_MEDIA,
        &SpeakerHostPinSupportedDeviceFormats[45].DataFormat
    }
};


// The entries must follow the same order as the filter's pin descriptor array.
static
PIN_DEVICE_FORMATS_AND_MODES SpeakerPinDeviceFormatsAndModes[] =
{
    {
        SystemRenderPin,
        SpeakerHostPinSupportedDeviceFormats,
        SIZEOF_ARRAY(SpeakerHostPinSupportedDeviceFormats),
        SpeakerHostPinSupportedDeviceModes,
        SIZEOF_ARRAY(SpeakerHostPinSupportedDeviceModes)
    },
    {
        BridgePin,
        NULL,
        0,
        NULL,
        0
    }
};

//=============================================================================
//
// Now we define the data-ranges for the streaming pin. 
// Multiple data-ranges support PCM (8-32 bit) and IEEE Float (32-bit),
// covering sample rates from 8kHz to 384kHz. The OS will match any requested 
// format within these ranges.
//
static
KSDATARANGE_AUDIO SpeakerPinDataRangesStream[] =
{
    {
        // --- KSDATARANGE header part (must be first) ---
        // PCM format range
        {
            sizeof(KSDATARANGE_AUDIO),
            KSDATARANGE_ATTRIBUTES,
            0,
            0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },

        // --- KSDATARANGE_AUDIO fields ---
        8,       // MaximumChannels (supports up to 7.1)
        8,       // MinimumBitsPerSample
        32,      // MaximumBitsPerSample
        8000,    // MinimumSampleFrequency
        384000   // MaximumSampleFrequency
    },
    {
        // --- KSDATARANGE header part (must be first) ---
        // IEEE Float format range
        {
            sizeof(KSDATARANGE_AUDIO),
            KSDATARANGE_ATTRIBUTES,
            0,
            0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
        },

        // --- KSDATARANGE_AUDIO fields ---
        8,       // MaximumChannels (supports up to 7.1)
        32,      // MinimumBitsPerSample
        32,      // MaximumBitsPerSample
        8000,    // MinimumSampleFrequency
        384000   // MaximumSampleFrequency
    }
};


static
PKSDATARANGE SpeakerPinDataRangePointersStream[] =
{
    PKSDATARANGE(&SpeakerPinDataRangesStream[0]),
    PKSDATARANGE(&SpeakerPinDataRangesStream[1]),
    PKSDATARANGE(&PinDataRangeAttributeList),
};

//=============================================================================
static
KSDATARANGE SpeakerPinDataRangesBridge[] =
{
    {
        sizeof(KSDATARANGE),
        0,
        0,
        0,
        STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
        STATICGUIDOF(KSDATAFORMAT_SUBTYPE_ANALOG),
        STATICGUIDOF(KSDATAFORMAT_SPECIFIER_NONE)
    }
};

static
PKSDATARANGE SpeakerPinDataRangePointersBridge[] =
{
    &SpeakerPinDataRangesBridge[0]
};

//=============================================================================
static
PCPIN_DESCRIPTOR SpeakerWaveMiniportPins[] =
{
    // Wave Out Streaming Pin (Renderer) KSPIN_WAVE_RENDER3_SINK_SYSTEM
    {
        SPEAKER_MAX_INPUT_SYSTEM_STREAMS,
        SPEAKER_MAX_INPUT_SYSTEM_STREAMS,
        0,
        NULL,        // AutomationTable
        {
            0,
            NULL,
            0,
            NULL,
            SIZEOF_ARRAY(SpeakerPinDataRangePointersStream),
            SpeakerPinDataRangePointersStream,
            KSPIN_DATAFLOW_IN,
            KSPIN_COMMUNICATION_SINK,
            &KSCATEGORY_AUDIO,
            NULL,
            0
        }
    },
    // Wave Out Bridge Pin (Renderer) KSPIN_WAVE_RENDER3_SOURCE
    {
        0,
        0,
        0,
        NULL,
        {
            0,
            NULL,
            0,
            NULL,
            SIZEOF_ARRAY(SpeakerPinDataRangePointersBridge),
            SpeakerPinDataRangePointersBridge,
            KSPIN_DATAFLOW_OUT,
            KSPIN_COMMUNICATION_NONE,
            &KSCATEGORY_AUDIO,
            NULL,
            0
        }
    },
};

//=============================================================================
//
//                   ----------------------------      
//                   |                          |      
//  Host Pin     0-->|                          |--> 1 KSPIN_WAVE_RENDER3_SOURCE
//                   |                          |      
//                   ----------------------------
//
static
PCCONNECTION_DESCRIPTOR SpeakerWaveMiniportConnections[] =
{
    { PCFILTER_NODE, KSPIN_WAVE_RENDER3_SINK_SYSTEM, PCFILTER_NODE, KSPIN_WAVE_RENDER3_SOURCE }
};

//=============================================================================
static
PCPROPERTY_ITEM PropertiesSpeakerWaveFilter[] =
{
    {
        &KSPROPSETID_Pin,
        KSPROPERTY_PIN_PROPOSEDATAFORMAT,
        KSPROPERTY_TYPE_SET | KSPROPERTY_TYPE_BASICSUPPORT,
        PropertyHandler_WaveFilter
    },
    {
        &KSPROPSETID_Pin,
        KSPROPERTY_PIN_PROPOSEDATAFORMAT2,
        KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_BASICSUPPORT,
        PropertyHandler_WaveFilter
    }
};

DEFINE_PCAUTOMATION_TABLE_PROP(AutomationSpeakerWaveFilter, PropertiesSpeakerWaveFilter);

//=============================================================================
static
PCFILTER_DESCRIPTOR SpeakerWaveMiniportFilterDescriptor =
{
    0,                                              // Version
    &AutomationSpeakerWaveFilter,                   // AutomationTable
    sizeof(PCPIN_DESCRIPTOR),                       // PinSize
    SIZEOF_ARRAY(SpeakerWaveMiniportPins),          // PinCount
    SpeakerWaveMiniportPins,                        // Pins
    sizeof(PCNODE_DESCRIPTOR),                      // NodeSize
    0,                                              // NodeCount
    NULL,                                           // Nodes
    SIZEOF_ARRAY(SpeakerWaveMiniportConnections),   // ConnectionCount
    SpeakerWaveMiniportConnections,                 // Connections
    0,                                              // CategoryCount
    NULL                                            // Categories  - use defaults (audio, render, capture)
};

#endif // _VIRTUALAUDIODRIVER_SPEAKERWAVTABLE_H_
