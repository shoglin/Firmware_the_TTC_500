#------------------------ Tool Specifications & Options ----------------------

COMPILER  =  lcc

CC        =  "C:\Program Files\MATLAB\R2020b\sys\lcc64\lcc64\bin\lcc64.exe"
LD        =  "C:\Program Files\MATLAB\R2020b\sys\lcc64\lcc64\bin\lcclnk64.exe"
LIBCMD    =  "C:\Program Files\MATLAB\R2020b\sys\lcc64\lcc64\bin\lcclib64.exe"
CFLAGS    =  -dll -noregistrylookup  -c -Zp8 -DLCC_WIN64 -DMATLAB_MEX_FILE -nodeclspec
LDFLAGS   =  -s -dll -entry LibMain RYDsbOhYZlKJH25h4Uv02G_cclib.def -L"C:\Program Files\MATLAB\R2020b\sys\lcc64\lcc64\lib64"

OBJECTS = \
	   slcc_interface_RYDsbOhYZlKJH25h4Uv02G.obj \
	   lccstub.obj \

STATICLIBS = \

#------------------------------ Include/Lib Path ------------------------------

INCLUDE_PATH = \
     -I"c:\program files\matlab\r2020b\extern\include" \
     -I"c:\program files\matlab\r2020b\simulink\include" \
     -I"c:\users\lobachev\desktop\shoglin_folder_for_job\3. searching_error_in_the_model_and_the firmware\mlprj\slprj\_slcc\rydsbohyzlkjh25h4uv02g" \
     -I"c:\users\muravev\desktop\dumpersoftware\classes" \
     -I"c:\users\lobachev\desktop\shoglin_folder_for_job\3. searching_error_in_the_model_and_the firmware\mlprj\classes" \
     -I"c:\users\lobachev\desktop\shoglin_folder_for_job\3. searching_error_in_the_model_and_the firmware\mlprj" \
     -I"c:\users\lobachev\desktop\shoglin_folder_for_job\2. c_code_for_one_pin\project\ttctest\mlprj" \
     -I"c:\program files\matlab\r2020b\sys\lcc64\lcc64\include64" \
     -I"c:\program files\matlab\r2020b\sys\lcc64\lcc64\mex" \

#--------------------------------- Rules --------------------------------------

RYDsbOhYZlKJH25h4Uv02G_cclib.dll : $(MAKEFILE) $(OBJECTS)
	$(LD) $(LDFLAGS) /OUT:RYDsbOhYZlKJH25h4Uv02G_cclib.dll $(OBJECTS)  $(STATICLIBS) "C:\Program Files\MATLAB\R2020b\extern\lib\win64\microsoft\libmex.lib" "C:\Program Files\MATLAB\R2020b\extern\lib\win64\microsoft\libmx.lib"
slcc_interface_RYDsbOhYZlKJH25h4Uv02G.obj :	C:\Users\lobachev\Desktop\SHOGLI~1\3F403~1.SEA\MLPrj\slprj\_slcc\RYDSBO~1\SLCC_I~1.C
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Users\lobachev\Desktop\Shoglin_folder_for_job\3. Searching_error_in_the_model_and_the firmware\MLPrj\slprj\_slcc\RYDsbOhYZlKJH25h4Uv02G\slcc_interface_RYDsbOhYZlKJH25h4Uv02G.c"
lccstub.obj :	C:\PROGRA~1\MATLAB\R2020b\sys\lcc64\lcc64\mex\lccstub.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2020b\sys\lcc64\lcc64\mex\lccstub.c"
