
add_library(${REGISTERS_DEFINITION_LIB_NAME} 
./RegistersDefinition.hpp 
./ByteDefinition.hpp

./GeneralConfigurationRegistersAndAESDeclaration.cpp
./GeneralConfigurationRegistersAndAESDefinition.hpp

./STSConfigurationAndStatusRegistersDeclaration.cpp
./STSConfigurationAndStatusRegistersDefinition.hpp

./ReceiverTuningParametersDeclaration.cpp
./ReceiverTuningParametersDefinition.hpp

./ExternalSyncControlAndRxCalibrationDeclaration.cpp
./ExternalSyncControlAndRxCalibrationDefinition.hpp

./GpioControlAndStatusDeclaration.cpp
./GpioControlAndStatusDefinition.hpp

./DigitalReceiverConfigurationDeclaration.cpp
./DigitalReceiverConfigurationDefinition.hpp

./AnalogRfConfigurationBlockDeclaration.cpp
./AnalogRfConfigurationBlockDefinition.hpp

)

