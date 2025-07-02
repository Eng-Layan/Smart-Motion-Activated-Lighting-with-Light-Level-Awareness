% Smart_Motion_Lighting_Analysis.m
% MATLAB visualization for Smart Motion-Activated Lighting with Light Level Awareness

clear;
clc;

% Adjust COM port as needed
s = serialport("COM3", 9600);
configureTerminator(s, "LF");
flush(s);

lightLevels = [];
motionStatus = [];
timestamps = [];

disp("Reading data from Arduino... Press Ctrl+C to stop.");

figure;
hold on;
grid on;
xlabel('Time (s)');
ylabel('Light Level (%)');
title('Smart Motion-Activated Lighting - Light Levels Over Time');

startTime = datetime('now');

while true
    dataLine = readline(s);
    disp(dataLine);

   lightMatch = regexp(dataLine, 'Light: (\d+)', 'tokens');

if contains(dataLine, 'Motion Detected') && ~isempty(lightMatch)
    motion = 1;
elseif contains(dataLine, 'No Motion') && ~isempty(lightMatch)
    motion = 0;
else
    continue;
end

light = str2double(lightMatch{1}{1});


        elapsedTime = seconds(datetime('now') - startTime);

        motionStatus(end+1) = motion;
        lightLevels(end+1) = light;
        timestamps(end+1) = elapsedTime;

        plot(timestamps, lightLevels, 'b.-');
        drawnow;
    end

