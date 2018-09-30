cmake_minimum_required(VERSION 3.12)
project(DocDB)

set(CMAKE_CXX_STANDARD 14)

add_executable(DocDB main.cpp WSDON/WSDONParser.cpp WSDON/WSDONParser.h WSDON/WSDONUtility.cpp WSDON/WSDONUtility.h WSDON/WSDONSerializer.cpp WSDON/WSDONSerializer.h WSDON/Structure/WSDONDocument.h WSDON/Structure/WSDONObject.h IO/FileWriter.cpp IO/FileWriter.h IO/FileReader.cpp IO/FileReader.h DocumentManagement/Docuemnts/Data/DataDocumentManager.cpp DocumentManagement/Docuemnts/Data/DataDocumentManager.h DocumentManagement/Docuemnts/Structure/DataDocument.h DocumentManagement/Docuemnts/CommonUtility/DocumentUtility.cpp DocumentManagement/Docuemnts/CommonUtility/DocumentUtility.h IO/FileSystem/CrossFileSystemUtility.cpp IO/FileSystem/CrossFileSystemUtility.h DocumentManagement/Docuemnts/Structure/DocumentMetaData.h)