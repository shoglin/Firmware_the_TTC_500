function generateEnumHeaderFromIntEnumClasses(headerFileName)

%% находим находим текущую папку для работы
    scriptFullPath = mfilename('fullpath');
    scriptDir      = fileparts(scriptFullPath);
    folderPath     = scriptDir;

 %% если имя не задано в функций то будет название swcAppEnumTypes.h
    if nargin < 1 || isempty(headerFileName)
        headerFileName = 'swcAppEnumTypes.h';
    end

%% добавля текущую папку в путь
    addpath(folderPath);

%% находим все файли находим все файили . m
    mfiles = dir(fullfile(folderPath, '*.m'));

%% определяем какие для файли создание enum
    enumClasses = {};
    for k = 1:numel(mfiles)
        
        %получаем имя файла без  . m
        [~, name] = fileparts(mfiles(k).name);

        % Получить информацию о class
        try
            mc = meta.class.fromName(name);
        catch
            mc = [];
        end

        if isempty(mc)
            continue;
        end

%Сохранение информации о class если class Simulink.IntEnumType
        isIntEnum = any(arrayfun(@(s) strcmp(s.Name, 'Simulink.IntEnumType'), ...
                                 mc.SuperclassList));
        if isIntEnum
            enumClasses{end+1} = mc; 
        end
    end

    if isempty(enumClasses)
        warning('No Simulink.IntEnumType subclasses found in "%s".', folderPath);
        return;
    end

%% Открытия файла для записи и перезаписи хедер файл
    headerFullPath = fullfile(folderPath, headerFileName);
    fid = fopen(headerFullPath, 'w');
    if fid == -1
        error('Cannot open header file "%s" for writing.', headerFullPath);
    end
% авто закрытие файла 
    cleanupObj = onCleanup(@() fclose(fid)); 

%пишим врехние ifndtf define хедера
    guardName = upper(strrep(headerFileName, '.', '_'));
    fprintf(fid, "#ifndef %s\n", guardName);
    fprintf(fid, "#define %s\n\n\n", guardName);


    for cIdx = 1:numel(enumClasses)
        
        %получаем имя класса и простое имя класс для записи в хедер
        mc = enumClasses{cIdx};
        className = mc.Name;              
        [~, simpleClassName] = fileparts(className);

        
        try
            [enumObjs, enumNames] = enumeration(className); %находим все имена enum и их значения
        catch ME
            warning('Could not get enumeration info for "%s": %s', className, ME.message);
            continue;
        end

        if isempty(enumObjs)
            continue;
        end

        fprintf(fid, "typedef enum {\n"); % пишим typedef чтоб обявит enum

        
        %записываем все имена enum и их значения 
        numEnums = numel(enumObjs);
        for i = 1:numEnums
            enumName  = enumNames{i};
            enumValue = int32(enumObjs(i));   

            if i == numEnums
                fprintf(fid, "    %s = %d\n", enumName, enumValue);
            else
                fprintf(fid, "    %s = %d,\n", enumName, enumValue);
            end
        end
        % закрываем обозначения enum
        fprintf(fid, "} %s;\n\n", simpleClassName);
    end

    % последния строка хедер
    fprintf(fid, "#endif /* %s */\n", guardName);

    fprintf('Header generated: %s\n', headerFullPath);
end
