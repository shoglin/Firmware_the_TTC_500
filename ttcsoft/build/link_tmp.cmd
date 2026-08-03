./build/convAIVoltageData.obj ./build/CAN_Properties.obj ./build/convAICurrentData.obj ./build/VCU_SW.obj ./build/ert_main.obj ./build/Pin_Init.obj ./build/convDIOSttToEnum.obj                                       
-o build/app.out                                                 
-l ./lib/ttc500.lib                             
-l ./lib/bsp.lib                         
-l "C:\ti\ccs1220\ccs\tools\compiler\arm_5.1.6\bin/../lib/rtsv7R4_T_be_v3D16_eabi.lib"                                         
./bsp/mem_ttc500_bl.lsf                                    
-m ./build/app.map                        
--reread_libs --rom_model --warn_sections --be32 --mapfile_contents=all --issue_remarks --display_error_number --disable_auto_rts --fill_value=0 --minimize_trampolines --diag_suppress=10068                                             
