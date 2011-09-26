#ifndef ALSA_AUDIO_DRIVER_H
#define ALSA_AUDIO_DRIVER_H

#include <QtCore>

#include <asoundlib.h>

#include <mt32emu/mt32emu.h>

#include "AudioDriver.h"
#include "../ClockSync.h"

class Master;
class QSynth;
class AlsaAudioDriver;

class AlsaAudioStream : public AudioStream {
private:
	ClockSync clockSync;
	QSynth *synth;
	unsigned int sampleRate;
	int currentDeviceIndex;
	MT32Emu::Bit16s *buffer;
	snd_pcm_t *stream;
	// The number of nanos by which to delay (MIDI) events to help ensure accurate relative timing.
	qint64 sampleCount;
	bool pendingClose;

	static void* processingThread(void *);

public:
	AlsaAudioStream(QSynth *useSynth, unsigned int useSampleRate);
	~AlsaAudioStream();
	bool start();
	void close();
};

class AlsaAudioDefaultDevice : public AudioDevice {
friend class AlsaAudioDriver;
	AlsaAudioDefaultDevice(AlsaAudioDriver *driver);
public:
	AlsaAudioStream *startAudioStream(QSynth *synth, unsigned int sampleRate) const;
}; 

class AlsaAudioDriver : public AudioDriver {
public:
	AlsaAudioDriver(Master *useMaster);
	~AlsaAudioDriver();
	QList<AudioDevice *> getDeviceList();
};

#endif