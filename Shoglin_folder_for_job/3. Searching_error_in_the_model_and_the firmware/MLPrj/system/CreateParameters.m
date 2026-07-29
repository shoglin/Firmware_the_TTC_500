function CreateParameters( ParList )

m = size(ParList,1);

for i = 1:m
    temp_var = Simulink.Parameter;
    temp_var.Value = ParList{i,2}; 
    temp_var.DataType = ParList{i,6};
    if ~isempty(ParList{i,3})
        temp_var.Min = ParList{i,3}(1);
        temp_var.Max = ParList{i,3}(2);
    end
    temp_var.DocUnits = ParList{i,4};
    temp_var.Description = ParList{i,5};
	temp_var.CoderInfo.StorageClass = ParList{i,7}; 
    assignin('base',ParList{i,1},temp_var);
    clear temp_var;
end

end

