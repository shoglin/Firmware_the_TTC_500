classdef (Enumeration) StateModeTypes < Simulink.IntEnumType
    enumeration
        STT_DISABLE (0)
        STT_ENABLE (1)
        STT_RESERVED (2)
        STT_DEFAULT (3)
        STT_ERROR (4)
    end

    methods (Static = true)
        function hdrFile = getHeaderFile()
            hdrFile = 'swcAppEnumTypes.h';
        end  

        function descr = getDescription()
            descr = 'Type definition of States';
        end

        function dataScope = getDataScope()
            dataScope = 'Imported';
        end

        function retVal = getDefaultValue()
            retVal = StateModeTypes.STT_DEFAULT;
        end

        function retVal = addClassNameToEnumNames()
            retVal = false;
        end
    end
end
