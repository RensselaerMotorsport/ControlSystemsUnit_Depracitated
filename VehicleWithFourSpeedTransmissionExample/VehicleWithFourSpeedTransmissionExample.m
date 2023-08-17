%% Vehicle with Four-Speed Transmission
%
% This example shows a complete vehicle with Simscape(TM) Driveline(TM)
% components, including the engine, drivetrain, four-speed transmission,
% tires, and longitudinal vehicle dynamics. The transmission controller is
% implemented as a state machine in Stateflow(R), selecting the gear based
% on throttle and vehicle speed.  
% 
% 
% Copyright 2008-2017 The MathWorks, Inc.



%% Model

open_system('VehicleWithFourSpeedTransmission')

set_param(find_system('VehicleWithFourSpeedTransmission','MatchFilter', @Simulink.match.allVariants,'FindAll', 'on','type','annotation','Tag','ModelFeatures'),'Interpreter','off')

%% Transmission Subsystem

open_system('VehicleWithFourSpeedTransmission/Transmission','force')

%% Clutch Schedule Subsystem

open_system('VehicleWithFourSpeedTransmission/Transmission/Clutch Schedule','force')

%% Shift Logic Subsystem

open_system('VehicleWithFourSpeedTransmission/Shift Logic','force')

%% Vehicle Body Subsystem

open_system('VehicleWithFourSpeedTransmission/Vehicle Body','force')

%% Simulation Results from Simscape Logging
%%
%
% The plot below shows the input and output shaft speeds of the
% transmission as well as the vehicle speed.  The clutch states are also
% plotted (locked or open), indicating the selected gear of the transmission.
%


VehicleWithFourSpeedTransmissionPlot1Speed;

%%

