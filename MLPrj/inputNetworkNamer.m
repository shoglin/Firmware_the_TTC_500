function inputNetworkNamer()
        
   %Составление списка блоков
    blockPaths = find_system([bdroot '/InputData/InputNetwork'], ...
        'BlockType', 'S-Function', ...
        'FunctionName', 'scanunpack');
    
    %Осуществляем поиск блоков CAN Unpack внутри указанной подсистемы
    %модели, переименовываем блоки анпаков и драйверов в соответствии с
    %именами сообщений. Проверяем корректность 

    cnt = 0;
    
    %Поиск требуемых блоков
    for i = 1:numel(blockPaths)
        %Достаем имя сообщения
        msgName = get_param ( blockPaths{i}, 'MsgName' );
        %Достаем ID сообщения
        msgID = get_param ( blockPaths{i}, 'MsgIdentifier' );
        portInfo = get_param(blockPaths{i}, 'PortConnectivity');
        objName = get_param(portInfo(1).SrcBlock, 'FunctionName');
        if strcmp( objName, 'canRead_ttc500' )
            drvMsgID = get_param(portInfo(1).SrcBlock, 'id');
            if ~strcmp( msgID, drvMsgID)
                set_param(portInfo(1).SrcBlock, 'id', msgID);
                cnt = cnt + 1;
            end
            set_param( portInfo(1).SrcBlock, 'Name', ['read_message_' msgName] );
        end
        %Достаем подсистему канпака
        curPath = get_param( blockPaths{i}, 'Parent' );
        %Переименуем канпак
        set_param( blockPaths{i}, 'Name', ['CANUnpack_' msgName] );
        %Вычленяем из ID SA
        SA = num2str(bitand(str2double(msgID),255),'%02x');
        %Добавляем SA к названию сообщения и переименовываем подсистему
        if ~endsWith( msgName, ['_' SA] )
            set_param(curPath, 'Name', [msgName '_' SA]);
        end
    end
    disp(['Количество ошибок в ID ', num2str(cnt)]);

end
    