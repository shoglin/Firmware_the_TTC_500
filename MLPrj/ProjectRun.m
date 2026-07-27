clear all %#ok

disp('Create Structures...');
try
    run('ProjectBusesCAN');
    canMessageBusType;
catch
    error('Problem with Structures creating. Operation aborted.');
end
disp('Structures created successfully');

disp('Create parameters and signals...');
try
    run('globalParametersData');
catch
    error('Problem with Parameters and Signals creating. Operation aborted.');
end
disp('Parameters and Signals created successfully');

disp('All done');