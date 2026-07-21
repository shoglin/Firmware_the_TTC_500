function CreateSignals( SigList )

m = size(SigList,1);

for i = 1:m
    temp_var = Simulink.Signal;
    temp_var.InitialValue = '0';
    temp_var.DataType = SigList{i,5};
    temp_var.Min = SigList{i,2}(1);
    temp_var.Max = SigList{i,2}(2);
    temp_var.DocUnits = SigList{i,3};
    temp_var.Description = SigList{i,4};
    temp_var.CoderInfo.StorageClass = 'ExportedGlobal';
    temp_var.Complexity = 'real';
    assignin('base',SigList{i,1},temp_var);
    clear temp_var;
end

end

