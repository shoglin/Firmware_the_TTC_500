function [Signals, Parameters] = globalParametersData()
%% Software Parameters definition

Parameters = {

'pHPumpVolume',                 100,                [0 1000],           'cm3',    '-',    'single',   'ExportedGlobal';
'pHMotorVolume',                160,                [0 1000],           'cm3',    '-',    'single',   'ExportedGlobal';

};



%% Software Signals definition

Signals = {

};

CreateParameters(Parameters);
CreateSignals(Signals);

clear Parameters;
clear Signals;

end