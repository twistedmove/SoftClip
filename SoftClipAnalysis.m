hostedPlugin = loadAudioPlugin('SoftClip.vst3');
hostedPlugin.InputGain = 10.0;
hostedPlugin.ClippingAlgorithm = 'Arctan';


% Sampling rate
fs = 48000;

setSampleRate(hostedPlugin, fs);

% Frequency of sine wave (Hz)
f = 2;

% Time of one sample
ts = 1 / fs;

% Nyquist frequency 
nyq = fs / 2;

% Time vector
t = [0:ts:1-ts];

% Make sine wave
x = sin(2*pi*f*t);

% Process function requires stereo input to plugin
audioIn = [x;x]';

% Run sine wave through plugin
audioOut = process(hostedPlugin,audioIn);

% Plot processed vs original 
figure(1)
subplot(1,2,1)
plot(t,x,t,audioOut(:,1));
xlabel('Time (sec.)'); ylabel('Amplitude');
title('Waveform');

subplot(1,2,2)
plot(x,x,x,audioOut(:,1));
xlabel('Input Amplitude'); ylabel('Output Amplitude');
legend('Linear', 'Distortion'); title('Characteristic Curve');

% Plot THD
f = 2500;

% Make sine wave
x = sin(2*pi*f*t);

% Process function requires stereo input to plugin
audioIn = [x;x]';

% Run sine wave through plugin
audioOut = process(hostedPlugin,audioIn);

figure(2)
thd(audioOut(:,1), fs, 5);
axis([0 24 -50 0])
r = thd(audioOut(:,1), fs);
percentTHD = 10^(r/20) * 100


