% Code to plot simulation results from VehicleWithFourSpeedTransmission
%% Plot Description:
%
% The plot below shows the input and output shaft speeds of the
% transmission as well as the vehicle speed.  The clutch states are also
% plotted (locked or open), indicating the selected gear of the transmission.

% Copyright 2016 The MathWorks, Inc.

% Generate simulation results if they don't exist
if ~exist('simlog_VehicleWithFourSpeedTransmission', 'var')
    sim('VehicleWithFourSpeedTransmission')
end

% Reuse figure if it exists, else create new figure
if ~exist('h1_VehicleWithFourSpeedTransmission', 'var') || ...
        ~isgraphics(h1_VehicleWithFourSpeedTransmission, 'figure')
    h1_VehicleWithFourSpeedTransmission = figure('Name', 'VehicleWithFourSpeedTransmission');
end
figure(h1_VehicleWithFourSpeedTransmission)
clf(h1_VehicleWithFourSpeedTransmission)

% Get simulation results
simlog_t = simlog_VehicleWithFourSpeedTransmission.Inertia_Input_Shaft.w.series.time;
simlog_wTransInp = simlog_VehicleWithFourSpeedTransmission.Inertia_Input_Shaft.w.series.values('rpm');
simlog_wTransOut = simlog_VehicleWithFourSpeedTransmission.Inertia_Output_Shaft.w.series.values('rpm');
simlog_vVeh = simlog_VehicleWithFourSpeedTransmission.Vehicle_Body.Vehicle_Body.v.series.values('mph');

temp_clutchState = logsout_VehicleWithFourSpeedTransmission.get('Clutch_States');

% Plot results
simlog_handles(1) = subplot(2, 1, 1);
yyaxis left
plot(simlog_t, simlog_wTransInp, 'LineWidth', 1)
hold on
plot(simlog_t, simlog_wTransOut, 'LineWidth', 1)
hold off
ylabel('Speed (RPM)')
yyaxis right
plot(simlog_t, simlog_vVeh, 'LineWidth', 1)
grid on
ylabel('Speed (mph)')
title('Shaft Speeds and Vehicle Speed')
legend({'Input','Output','Vehicle'},'Location','SouthEast');

simlog_handles(2) = subplot(2, 1, 2);
plot(temp_clutchState.Values.Time, temp_clutchState.Values.Data+...
    repmat((4:-1:0),size(temp_clutchState.Values.Data,1),1), 'LineWidth', 1)
grid on
set(gca,'YLim',[0 5])
set(gca,'YTick',(0:1:5));
set(gca,'YTickLabel',{'' '' '' '' 'open' 'locked' })
title('Clutch States')
ylabel('State')
xlabel('Time (s)')
legend({'A','B','C','D','R'},'Location','Best');

linkaxes(simlog_handles, 'x')

% Remove temporary variables
clear simlog_t simlog_handles
clear simlog_wTransInp simlog_wTransOut temp_clutchState simlog_vVeh

