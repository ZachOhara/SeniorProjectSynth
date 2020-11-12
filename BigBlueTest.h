#pragma once

#include "IPlug_include_in_plug_hdr.h"

#include "IGraphicsStructs.h"
#include "IControls.h"

#include "BigBlueAudioModule.h"
#include "BigBlueGraphics.h"
#include "VoiceManager.h"
#include "TuningProcessor.h"
#include "Oscillator.h"

#include <vector>

const int kNumPresets = 1;

const iplug::igraphics::IColor COLOR_MAT_BGRAY900(255, 38, 50, 56);

enum EParams
{
  kOsc1OctavePid,
  kOsc1WaveformPid,
  kOsc1SemitonePid,
  kOsc1DetunePid,
  kOsc2OctavePid,
  kOsc2WaveformPid,
  kOsc2SemitonePid,
  kOsc2DetunePid,
  kNumParams
};

using namespace iplug;
using namespace igraphics;

class BigBluePlugin : public Plugin
{
public:
  BigBluePlugin(const InstanceInfo& info, int nParams, int nPresets);

  void RegisterModule(BigBlueAudioModule* module);

  void OnReset() override;

private:
  std::vector<BigBlueAudioModule*> mModules;
};

class BigBlueTest final : public BigBluePlugin
{
public:
  BigBlueTest(const InstanceInfo& info);

  void OnParamChange(int pid) override;
  void ProcessMidiMsg(const IMidiMsg& msg) override;
  void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;

private:
  VoiceManager mVoiceManager;
  TuningProcessor mTuningProc;
  Oscillator mOscillator;
};
