of generated files to ccs project folder
modelName = bdroot;

mainDirectory = pwd;
% get path
%currentPath = 'C:\git\herculessoft';
cd ..\
upperMain = pwd;
currentPath = [upperMain '\ttcsoft'];

cd(mainDirectory);

sourcePath = strcat(currentPath, '\src');
includePath = strcat(currentPath, '\inc');

%from slprj

%list of headers
listOfHeaders = dir('slprj/ttc_500_series/**/*.h');

for i = 1:length(listOfHeaders)
  cd(listOfHeaders(i).folder);
  copyfile(listOfHeaders(i).name, includePath);  
end

cd(mainDirectory);
%list of sourse
listOfCode = dir('slprj/ttc_500_series/**/*.c');

for i = 1:length(listOfCode)
  cd(listOfCode(i).folder);
  copyfile(listOfCode(i).name, sourcePath);  
end

%from top model

folderName = strcat(modelName, '_ttc_500_series');

cd(strcat(mainDirectory, '\', folderName));

listOfHeaders = dir('*.h');

for i = 1:length(listOfHeaders)
  copyfile(listOfHeaders(i).name, includePath);  
end

%list of sourse
listOfCode = dir('*.c');

for i = 1:length(listOfCode)
  copyfile(listOfCode(i).name, sourcePath);  
end

cd(mainDirectory);

folderEnum = strcat(mainDirectory, '\classes');
cd(folderEnum);
copyfile('swcAppEnumTypes.h', includePath);


cd(mainDirectory);
