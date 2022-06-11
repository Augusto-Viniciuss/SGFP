cmake_minimum_required(VERSION 3.5)

project(SGFP_GUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
	cadastroWindow.h
	cadastroWindow.cpp
	cadastroWindow.ui
	modificarWindow.h
	modificarWindow.cpp
	modificarWindow.ui
	Arquivo.h
	Arquivo.cpp
	Data.h
	Data.cpp
	Diretor.h
	Diretor.cpp
	Empresa.h
	Empresa.cpp
	Endereco.h
	Endereco.cpp
	Funcionario.h
	Funcionario.cpp
	Gerente.h
	Gerente.cpp
	HistoricoArquivo.h
	HistoricoArquivo.cpp
	Operador.h
	Operador.cpp
	Pessoa.h
	Pessoa.cpp
	Presidente.h
	Presidente.cpp
	TelefoneException.h
	TelefoneException.cpp
	FuncionarioJaCadastradoExcept.h
	FuncionarioNaoEstaCadastradoExcept.h
	CPFException.h
	CPFException.cpp
	ArquivoNaoExisteExcept.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SGFP_GUI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SGFP_GUI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SGFP_GUI SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SGFP_GUI
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SGFP_GUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(SGFP_GUI PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SGFP_GUI)
endif()
