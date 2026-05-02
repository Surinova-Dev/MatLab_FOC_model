###########################################################################
## Makefile generated for component 'PMSM_to_BLDC_mod1'. 
## 
## Makefile     : PMSM_to_BLDC_mod1.mk
## Generated on : Sat May 02 12:34:56 2026
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/PMSM_to_BLDC_mod1.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file

PRODUCT_NAME              = PMSM_to_BLDC_mod1
MAKEFILE                  = PMSM_to_BLDC_mod1.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2025b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2025b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/FOC_MO~1
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
COMPILER_COMMAND_FILE     = PMSM_to_BLDC_mod1_comp.rsp
CMD_FILE                  = PMSM_to_BLDC_mod1.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
LIBSSC_SLI_OBJS           = ./ssc_sli_01dba599.c.o ./ssc_sli_0267402d.c.o ./ssc_sli_050be629.c.o ./ssc_sli_06b10db7.c.o ./ssc_sli_0763c151.c.o ./ssc_sli_0bd269e6.c.o ./ssc_sli_10d0a0c3.c.o ./ssc_sli_1367f522.c.o ./ssc_sli_136f97a1.c.o ./ssc_sli_1e0f233a.c.o ./ssc_sli_256cd57f.c.o ./ssc_sli_27094491.c.o ./ssc_sli_2f6ea1cd.c.o ./ssc_sli_2f6ec032.c.o ./ssc_sli_360cfd63.c.o ./ssc_sli_37d957ac.c.o ./ssc_sli_3b68442e.c.o ./ssc_sli_3fb4607e.c.o ./ssc_sli_40d3bd6c.c.o ./ssc_sli_40d56d93.c.o ./ssc_sli_40d5da0a.c.o ./ssc_sli_43618287.c.o ./ssc_sli_4363e48f.c.o ./ssc_sli_466b08dd.c.o ./ssc_sli_4e028390.c.o ./ssc_sli_550a4805.c.o ./ssc_sli_56b8ac8d.c.o ./ssc_sli_59b886b8.c.o ./ssc_sli_5a0cb974.c.o ./ssc_sli_5d63155c.c.o ./ssc_sli_5d65a733.c.o ./ssc_sli_5d671b0e.c.o ./ssc_sli_5f0de15a.c.o ./ssc_sli_60b93a56.c.o ./ssc_sli_62d81790.c.o ./ssc_sli_65bed6fb.c.o ./ssc_sli_66095472.c.o ./ssc_sli_77063d8b.c.o ./ssc_sli_7a618260.c.o ./ssc_sli_7bb5f2e0.c.o ./ssc_sli_89d0f30a.c.o ./ssc_sli_8a64c4e2.c.o ./ssc_sli_8d09009a.c.o ./ssc_sli_9abcdb7f.c.o ./ssc_sli_9b61793b.c.o ./ssc_sli_9c030181.c.o ./ssc_sli_9c0cb889.c.o ./ssc_sli_9dd1cff8.c.o ./ssc_sli_a1da431d.c.o ./ssc_sli_a4dfa663.c.o ./ssc_sli_a9bd7181.c.o ./ssc_sli_af031838.c.o ./ssc_sli_af04cdba.c.o ./ssc_sli_b0d5246e.c.o ./ssc_sli_b10f504c.c.o ./ssc_sli_b2b1d316.c.o ./ssc_sli_b5d8ca33.c.o ./ssc_sli_b9610f5b.c.o ./ssc_sli_bad3eeab.c.o ./ssc_sli_c7dda239.c.o ./ssc_sli_d06e19e0.c.o ./ssc_sli_d3d59c3a.c.o ./ssc_sli_d56e4e2b.c.o ./ssc_sli_dcd66f69.c.o ./ssc_sli_eb0a5702.c.o ./ssc_sli_eb0f3853.c.o ./ssc_sli_edb7e1b3.c.o ./ssc_sli_f508a54a.c.o ./ssc_sli_f76be39c.c.o ./ssc_sli_fa09e530.c.o ./ssc_sli_fa0ce53e.c.o ./ssc_sli_fbdf29da.c.o
LIBSSC_CORE_OBJS          = ./ssc_core_01dcc633.c.o ./ssc_core_04da2c69.c.o ./ssc_core_05058dd9.c.o ./ssc_core_06ba68a6.c.o ./ssc_core_09b5fa6e.c.o ./ssc_core_0a03aa58.c.o ./ssc_core_0bd666aa.c.o ./ssc_core_0cb8a17f.c.o ./ssc_core_0d65be6c.c.o ./ssc_core_0f019bd9.c.o ./ssc_core_0f0420a6.c.o ./ssc_core_0f09282e.c.o ./ssc_core_18bf4d77.c.o ./ssc_core_1c6b0332.c.o ./ssc_core_1fd25120.c.o ./ssc_core_24b4cdee.c.o ./ssc_core_280c0222.c.o ./ssc_core_2cd54448.c.o ./ssc_core_3169e4b7.c.o ./ssc_core_32d8b307.c.o ./ssc_core_3306c008.c.o ./ssc_core_360a4baf.c.o ./ssc_core_37d4ea84.c.o ./ssc_core_3e6774ce.c.o ./ssc_core_40db642d.c.o ./ssc_core_40dfdbdc.c.o ./ssc_core_41017299.c.o ./ssc_core_42b6ffa6.c.o ./ssc_core_4666b45b.c.o ./ssc_core_48b1386a.c.o ./ssc_core_4ad9135b.c.o ./ssc_core_4db6bd68.c.o ./ssc_core_4db86fcc.c.o ./ssc_core_4e03e39d.c.o ./ssc_core_4e04eecd.c.o ./ssc_core_4e06e3bd.c.o ./ssc_core_51d269ad.c.o ./ssc_core_54d55ae9.c.o ./ssc_core_5505224d.c.o ./ssc_core_550b4c41.c.o ./ssc_core_56b1a2bf.c.o ./ssc_core_576cd129.c.o ./ssc_core_59b034b8.c.o ./ssc_core_5d6ba758.c.o ./ssc_core_61629eca.c.o ./ssc_core_6607ea62.c.o ./ssc_core_67d1f118.c.o ./ssc_core_68da074b.c.o ./ssc_core_6b663a17.c.o ./ssc_core_6b6b89d2.c.o ./ssc_core_6dd833f3.c.o ./ssc_core_7209d3a5.c.o ./ssc_core_73d9c2b7.c.o ./ssc_core_76d825be.c.o ./ssc_core_770cead7.c.o ./ssc_core_7a613edb.c.o ./ssc_core_83db8762.c.o ./ssc_core_856738f2.c.o ./ssc_core_8569edc5.c.o ./ssc_core_89d7fa79.c.o ./ssc_core_8a6471dc.c.o ./ssc_core_8cd9cb37.c.o ./ssc_core_990fe1a4.c.o ./ssc_core_9b607b15.c.o ./ssc_core_9b671e57.c.o ./ssc_core_9c016445.c.o ./ssc_core_9c01d168.c.o ./ssc_core_9dd110ad.c.o ./ssc_core_9fb0e229.c.o ./ssc_core_9fb25b4f.c.o ./ssc_core_a269ab09.c.o ./ssc_core_a4d4c45e.c.o ./ssc_core_a4d6c217.c.o ./ssc_core_a4da1d0a.c.o ./ssc_core_a6b334b8.c.o ./ssc_core_a6b58a33.c.o ./ssc_core_a6b78ccc.c.o ./ssc_core_a76299bc.c.o ./ssc_core_a867d880.c.o ./ssc_core_a9bf1ff2.c.o ./ssc_core_aa09f23c.c.o ./ssc_core_abd05c18.c.o ./ssc_core_abd5e7b4.c.o ./ssc_core_acb64294.c.o ./ssc_core_acb6462e.c.o ./ssc_core_b1038cbb.c.o ./ssc_core_b10e34f4.c.o ./ssc_core_b2b3b239.c.o ./ssc_core_b369cd13.c.o ./ssc_core_b402b40d.c.o ./ssc_core_b5daad8d.c.o ./ssc_core_b7b88213.c.o ./ssc_core_b96ebc21.c.o ./ssc_core_bad68669.c.o ./ssc_core_bc648043.c.o ./ssc_core_bfdb08db.c.o ./ssc_core_c3003040.c.o ./ssc_core_c5b050d7.c.o ./ssc_core_c5b63cb2.c.o ./ssc_core_c607b660.c.o ./ssc_core_c8d83e88.c.o ./ssc_core_c9039339.c.o ./ssc_core_cab615c8.c.o ./ssc_core_cabdc251.c.o ./ssc_core_cabeaaaf.c.o ./ssc_core_cc0bcab0.c.o ./ssc_core_ce6a84bb.c.o ./ssc_core_d06d763c.c.o ./ssc_core_d3d34d7c.c.o ./ssc_core_d4b9397b.c.o ./ssc_core_d70a6a09.c.o ./ssc_core_d807fa59.c.o ./ssc_core_deb7fd8d.c.o ./ssc_core_e0d0866d.c.o ./ssc_core_e2b61d72.c.o ./ssc_core_e400c1c2.c.o ./ssc_core_ead8f455.c.o ./ssc_core_edb836de.c.o ./ssc_core_ee000fbe.c.o ./ssc_core_ee01086d.c.o ./ssc_core_f9b6dbed.c.o ./ssc_core_fa09e9e6.c.o ./ssc_core_fbd34e62.c.o
LIBPM_ST_OBJS             = ./pm_st_12be8102.c.o ./pm_st_43603aca.c.o ./pm_st_59ba8c5e.c.o ./pm_st_65b906f8.c.o ./pm_st_7a6183ce.c.o ./pm_st_7f64b2fa.c.o ./pm_st_870f70cf.c.o ./pm_st_a3b260e9.c.o ./pm_st_a7639c45.c.o ./pm_st_a868d115.c.o ./pm_st_d56af4a2.c.o ./pm_st_d56c266e.c.o
LIBMC_OBJS                = ./mc_04d8264b.c.o ./mc_050786f6.c.o ./mc_050ee5c1.c.o ./mc_06b4b0db.c.o ./mc_0860ee8a.c.o ./mc_0cb8196b.c.o ./mc_0d63602b.c.o ./mc_0d66ba95.c.o ./mc_1361f5a5.c.o ./mc_15d544b1.c.o ./mc_1663c1db.c.o ./mc_1669178c.c.o ./mc_17b2b909.c.o ./mc_17b70a99.c.o ./mc_18be9741.c.o ./mc_1fd05351.c.o ./mc_256bba9e.c.o ./mc_27064e3e.c.o ./mc_2d0630db.c.o ./mc_2f6ba92e.c.o ./mc_30b92ba0.c.o ./mc_316e8ecd.c.o ./mc_410dc6dd.c.o ./mc_42bcfe75.c.o ./mc_4368e8e9.c.o ./mc_436f3a90.c.o ./mc_4401f9e5.c.o ./mc_45d93f38.c.o ./mc_47b2c4ec.c.o ./mc_4c6caaa7.c.o ./mc_4dbcdca5.c.o ./mc_4e0fe18e.c.o ./mc_56bcae38.c.o ./mc_57680369.c.o ./mc_586d9cad.c.o ./mc_5a0a6cc3.c.o ./mc_5d67a19c.c.o ./mc_5ed62cca.c.o ./mc_6464144a.c.o ./mc_65b0d207.c.o ./mc_65b2d0c8.c.o ./mc_67dc4926.c.o ./mc_68dddb4b.c.o ./mc_690fc1bf.c.o ./mc_6b605e19.c.o ./mc_6ddde8f9.c.o ./mc_720ad3c3.c.o ./mc_720db216.c.o ./mc_7563a9d1.c.o ./mc_7803a56b.c.o ./mc_79deb076.c.o ./mc_7bb9909f.c.o ./mc_84b8497c.c.o ./mc_870c7565.c.o ./mc_880b5c40.c.o ./mc_8bbed717.c.o ./mc_916e0629.c.o ./mc_94605196.c.o ./mc_9b601681.c.o ./mc_9ddbabe4.c.o ./mc_9ddca961.c.o ./mc_9fbb8898.c.o ./mc_a1d39e4d.c.o ./mc_a1d627d1.c.o ./mc_a1d99098.c.o ./mc_a26aa4d4.c.o ./mc_a3b30e18.c.o ./mc_a5006377.c.o ./mc_a50a0cbe.c.o ./mc_aa099650.c.o ./mc_abd38dd6.c.o ./mc_aed8b9d2.c.o ./mc_aedf6e5a.c.o ./mc_af0477d5.c.o ./mc_b0dc45ca.c.o ./mc_b1035db7.c.o ./mc_b4000713.c.o ./mc_b7b18d60.c.o ./mc_b968d32c.c.o ./mc_bad68a7d.c.o ./mc_bfdd02f5.c.o ./mc_c16219bc.c.o ./mc_c162c223.c.o ./mc_c307e3dc.c.o ./mc_c46a93be.c.o ./mc_c90d9f89.c.o ./mc_cdd0dd5f.c.o ./mc_cdd8da52.c.o ./mc_d1b8dd6f.c.o ./mc_d204e67a.c.o ./mc_d6d6168f.c.o ./mc_d702d1e4.c.o ./mc_d9d8e9f3.c.o ./mc_dbb0a508.c.o ./mc_dbb3aff1.c.o ./mc_dbbfabc6.c.o ./mc_dcd0078a.c.o ./mc_e362bd71.c.o ./mc_e662eca6.c.o ./mc_e66336ff.c.o ./mc_e7b62a38.c.o ./mc_e8b1ba5c.c.o ./mc_edbe8c94.c.o ./mc_efd17762.c.o ./mc_f0002806.c.o ./mc_f1d0579f.c.o ./mc_f1d0e311.c.o ./mc_f1d15bd5.c.o ./mc_f3b173fc.c.o ./mc_f50bcfe0.c.o ./mc_f86b1ebb.c.o ./mc_f9b5db9f.c.o
LIBEX_OBJS                = ./ex_04d5441d.c.o ./ex_06bcd123.c.o ./ex_136645f8.c.o ./ex_17bc61ac.c.o ./ex_18b4440a.c.o ./ex_2bb3e2ac.c.o ./ex_2cdf97d7.c.o ./ex_2ebcd5b2.c.o ./ex_316a81de.c.o ./ex_316a8f13.c.o ./ex_36012fa7.c.o ./ex_40d5be33.c.o ./ex_440d4aba.c.o ./ex_45d28653.c.o ./ex_47b11894.c.o ./ex_47b17260.c.o ./ex_50027bf1.c.o ./ex_53bcffa7.c.o ./ex_57660158.c.o ./ex_60b4e4f8.c.o ./ex_690b7cd0.c.o ./ex_6dd531e9.c.o ./ex_6dd8e72d.c.o ./ex_76dd91b2.c.o ./ex_79d100f1.c.o ./ex_7cd25341.c.o ./ex_7d002618.c.o ./ex_81be18a2.c.o ./ex_8a6fc761.c.o ./ex_8ebb89cc.c.o ./ex_98d223a6.c.o ./ex_a1dafa44.c.o ./ex_acbcf277.c.o ./ex_aed5de1e.c.o ./ex_b2b40ad5.c.o ./ex_bb0efd4b.c.o ./ex_c9069dae.c.o ./ex_d9d686a8.c.o ./ex_debffef2.c.o ./ex_e10a4cd8.c.o ./ex_e40d74b8.c.o ./ex_eb0d559b.c.o ./ex_f26168b3.c.o ./ex_f6bb4c2d.c.o ./ex_f7688368.c.o ./ex_f866102d.c.o ./ex_f9b702ea.c.o
LIBPM_OBJS                = ./pm_26dc3230.c.o ./pm_3dd94032.c.o ./pm_466768a4.c.o ./pm_9dd7a82d.c.o ./pm_b103e88f.c.o ./pm_c60cb912.c.o

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU Tools for ARM Embedded Processors
# Supported Version(s):    
# ToolchainInfo Version:   2025b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_LOAD_CMD
# MW_GNU_ARM_TOOLS_PATH
# FDATASECTIONS_FLG

#-----------
# MACROS
#-----------

LIBGCC                    = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-libgcc-file-name}
LIBC                      = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libc.a}
LIBM                      = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libm.a}
PRODUCT_NAME_WITHOUT_EXTN = $(basename $(PRODUCT))
PRODUCT_BIN               = $(PRODUCT_NAME_WITHOUT_EXTN).bin
PRODUCT_HEX               = $(PRODUCT_NAME_WITHOUT_EXTN).hex
CPFLAGS                   = -O binary
SHELL                     = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU ARM Assembler
AS_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AS = "$(AS_PATH)/arm-none-eabi-gcc"

# C Compiler: GNU ARM C Compiler
CC_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CC = "$(CC_PATH)/arm-none-eabi-gcc"

# Linker: GNU ARM Linker
LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
LD = "$(LD_PATH)/arm-none-eabi-g++"

# C++ Compiler: GNU ARM C++ Compiler
CPP_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP = "$(CPP_PATH)/arm-none-eabi-g++"

# C++ Linker: GNU ARM C++ Linker
CPP_LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP_LD = "$(CPP_LD_PATH)/arm-none-eabi-g++"

# Archiver: GNU ARM Archiver
AR_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AR = "$(AR_PATH)/arm-none-eabi-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Binary Converter: Binary Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Hex Converter: Hex Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Executable Size: Executable Size
EXESIZEPATH = $(MW_GNU_ARM_TOOLS_PATH)
EXESIZE = "$(EXESIZEPATH)/arm-none-eabi-size"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /f/q
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
ASFLAGS              = -MMD -MP -MF"$(@:%.s.o=%.s.dep)" -MT"$@"  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = $(FDATASECTIONS_FLG) \
                       -Wall \
                       -c \
                       -MMD -MP -MF"$(@:%.c.o=%.c.dep)" -MT"$@"  \
                       -O0
CPPFLAGS             = -std=gnu++14 \
                       -fno-rtti \
                       -fno-exceptions \
                       $(FDATASECTIONS_FLG) \
                       -Wall \
                       -c \
                       -MMD -MP -MF"$(@:%.cpp.o=%.cpp.dep)" -MT"$@"  \
                       -O0
CPP_LDFLAGS          = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXESIZE_FLAGS        = $(PRODUCT)
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     = -O ihex $(PRODUCT) $(PRODUCT_HEX)
LDFLAGS              = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/PMSM_to_BLDC_mod1.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DUSE_FULL_LL_DRIVER -DSTM32F405xx -DUSE_HAL_DRIVER -DMW_TIMEBASESOURCE=TIM1 -DMW_GPIO_BIT_SHIFT=0
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=1
DEFINES_SKIPFORSIL = -DXCP_CUSTOM_PLATFORM -DXCP_MEM_DAQ_RESERVED_POOL_BLOCKS_NUMBER=10 -D__FPU_PRESENT=1U -D__FPU_USED=1U -DSTACK_SIZE=512 -DRT
DEFINES_STANDARD = -DMODEL=PMSM_to_BLDC_mod1 -DNUMST=2 -DNCSTATES=21 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
DEFINES_STM32DEVICEDRIVERBLOCKS = -DMW_TIM8_ENABLED=1

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD) $(DEFINES_STM32DEVICEDRIVERBLOCKS)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_dxf_p.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_tdxf_p.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_tdxy_p.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_dxy_p.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_obs_exp.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_dxf.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_obs_act.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_dnf_v_x.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_log.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_obs_all.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_f.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_acon_p.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_mcon_p.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_obs_il.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_tduf_p.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_gateway.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/rt_backsubrr_dbl.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/rt_forwardsubrr_dbl.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/rt_lu_real.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/rt_matrixlib_dbl.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_data.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/rtGetNaN.c $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/rt_nonfinite.c $(START_DIR)/SPI_code.c C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST0D6C~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/spi.c C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/adc.c C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/dma.c C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/gpio.c C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/tim.c C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/usart.c C:/ProgramData/MATLAB/SupportPackages/R2025b/toolbox/shared/supportpackages/stm32/src/overrideHALDelay.c C:/ProgramData/MATLAB/SupportPackages/R2025b/toolbox/shared/supportpackages/stm32/src/platform_timer.c $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/SysTickScheduler.c $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/main.c C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/STM32F~3.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/STM32F~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/STM32F~2.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST776E~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/STAC45~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/STF360~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST432B~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/STCF17~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST2FAB~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/STE597~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST2E9D~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/STB5DF~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST214E~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST3284~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/STBAE8~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST5F90~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST6219~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST28D3~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST1A52~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/STD26F~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST0779~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/STCE86~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/STM32F~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST2EEB~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST23DD~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/ST510D~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/STC40E~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/SYSTEM~1.C C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/STM32C~1/APPLIC~1/User/Core/syscalls.c C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/STM32C~1/APPLIC~1/User/Core/sysmem.c C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/STM32C~1/APPLIC~1/User/Startup/STARTU~1.S C:/ProgramData/MATLAB/SupportPackages/R2025b/toolbox/shared/supportpackages/stm32/src/stm_timer_ll.c

MAIN_SRC = $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = PMSM_to_BLDC_mod1_5da39267_1_ds.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_dxf_p.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_tdxf_p.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_tdxy_p.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_dxy_p.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_obs_exp.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_dxf.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_obs_act.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_dnf_v_x.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_log.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_obs_all.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_f.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_acon_p.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_mcon_p.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_obs_il.c.o PMSM_to_BLDC_mod1_5da39267_1_ds_tduf_p.c.o PMSM_to_BLDC_mod1_5da39267_1.c.o PMSM_to_BLDC_mod1_5da39267_1_gateway.c.o rt_backsubrr_dbl.c.o rt_forwardsubrr_dbl.c.o rt_lu_real.c.o rt_matrixlib_dbl.c.o PMSM_to_BLDC_mod1.c.o PMSM_to_BLDC_mod1_data.c.o rtGetNaN.c.o rt_nonfinite.c.o SPI_code.c.o stm32f4xx_hal_spi.c.o spi.c.o adc.c.o dma.c.o gpio.c.o tim.c.o usart.c.o overrideHALDelay.c.o platform_timer.c.o SysTickScheduler.c.o m3m4m4f_multitasking.c.o main.c.o stm32f4xx_it.c.o stm32f4xx_hal_msp.c.o stm32f4xx_hal_timebase_tim.c.o stm32f4xx_hal_tim.c.o stm32f4xx_hal_tim_ex.c.o stm32f4xx_ll_gpio.c.o stm32f4xx_ll_adc.c.o stm32f4xx_ll_dma.c.o stm32f4xx_ll_rcc.c.o stm32f4xx_ll_utils.c.o stm32f4xx_ll_exti.c.o stm32f4xx_hal_rcc.c.o stm32f4xx_hal_rcc_ex.c.o stm32f4xx_hal_flash.c.o stm32f4xx_hal_flash_ex.c.o stm32f4xx_hal_flash_ramfunc.c.o stm32f4xx_hal_gpio.c.o stm32f4xx_hal_dma_ex.c.o stm32f4xx_hal_dma.c.o stm32f4xx_hal_pwr.c.o stm32f4xx_hal_pwr_ex.c.o stm32f4xx_hal_cortex.c.o stm32f4xx_hal.c.o stm32f4xx_hal_exti.c.o stm32f4xx_ll_spi.c.o stm32f4xx_ll_tim.c.o stm32f4xx_ll_usart.c.o system_stm32f4xx.c.o syscalls.c.o sysmem.c.o startup_stm32f405rgtx.s.o stm_timer_ll.c.o

MAIN_OBJ = ert_main.c.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = ./ssc_sli.lib ./ssc_core.lib ./pm_st.lib ./mc.lib ./ex.lib ./pm.lib C:/ProgramData/MATLAB/SupportPackages/R2025b/3P.instrset/cmsis_dsp.instrset/Lib/GCC/arm_cortexm4ldfsp_math/libCMSISDSP.a C:/ProgramData/MATLAB/SupportPackages/R2025b/toolbox/shared/supportpackages/stm32/lib/GCC/libmw_pdmfilter_m4_spfp.lib

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard -ffp-contract=off
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard -ffp-contract=off
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nosys.specs  -T "C:\Users\Surinova\OneDrive - Surinova Pvt Ltd\Documents\Github\MatLab_FOC_model\F405_PMSM_Mod1\STM32CubeIDE\STM32F405RGTX_FLASH.ld"

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nosys.specs  -T "C:\Users\Surinova\OneDrive - Surinova Pvt Ltd\Documents\Github\MatLab_FOC_model\F405_PMSM_Mod1\STM32CubeIDE\STM32F405RGTX_FLASH.ld"

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nosys.specs  -T "C:\Users\Surinova\OneDrive - Surinova Pvt Ltd\Documents\Github\MatLab_FOC_model\F405_PMSM_Mod1\STM32CubeIDE\STM32F405RGTX_FLASH.ld"

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nosys.specs  -T "C:\Users\Surinova\OneDrive - Surinova Pvt Ltd\Documents\Github\MatLab_FOC_model\F405_PMSM_Mod1\STM32CubeIDE\STM32F405RGTX_FLASH.ld"

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


ALL_DEPS:=$(patsubst %.o,%.dep,$(ALL_OBJS))
all:

ifndef DISABLE_GCC_FUNCTION_DATA_SECTIONS
FDATASECTIONS_FLG := -ffunction-sections -fdata-sections
endif



-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include mw_gnu_arm_tools_path.mk
-include ../mw_gnu_arm_tools_path.mk
-include ../../mw_gnu_arm_tools_path.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)
	@echo "### Invoking postbuild tool "Binary Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_BIN)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Hex Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_HEX)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Executable Size" ..."
	$(EXESIZE) $(EXESIZE_FLAGS)
	@echo "### Done invoking postbuild tool."


download : postbuild


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.c.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : %.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/rtw/c/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/rtw/c/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/rtw/c/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/simulink/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/simulink/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/simulink/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/simulink/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_dxf_p.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_dxf_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_tdxf_p.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_tdxf_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_tdxy_p.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_tdxy_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_dxy_p.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_dxy_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_obs_exp.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_obs_exp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_dxf.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_dxf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_obs_act.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_obs_act.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_dnf_v_x.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_dnf_v_x.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_log.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_log.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_obs_all.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_obs_all.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_f.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_f.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_acon_p.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_acon_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_mcon_p.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_mcon_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_obs_il.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_obs_il.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_ds_tduf_p.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_ds_tduf_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_5da39267_1_gateway.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_5da39267_1_gateway.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_backsubrr_dbl.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/rt_backsubrr_dbl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_forwardsubrr_dbl.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/rt_forwardsubrr_dbl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_lu_real.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/rt_lu_real.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_matrixlib_dbl.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/rt_matrixlib_dbl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PMSM_to_BLDC_mod1_data.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/PMSM_to_BLDC_mod1_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.c.o : $(START_DIR)/PMSM_to_BLDC_mod1_ert_rtw/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


SPI_code.c.o : $(START_DIR)/SPI_code.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_spi.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_spi.c
	$(CC) $(CFLAGS) -o "$@" "$<"


spi.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/spi.c
	$(CC) $(CFLAGS) -o "$@" "$<"


adc.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/adc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


dma.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/dma.c
	$(CC) $(CFLAGS) -o "$@" "$<"


gpio.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/gpio.c
	$(CC) $(CFLAGS) -o "$@" "$<"


tim.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


usart.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/usart.c
	$(CC) $(CFLAGS) -o "$@" "$<"


overrideHALDelay.c.o : C:/ProgramData/MATLAB/SupportPackages/R2025b/toolbox/shared/supportpackages/stm32/src/overrideHALDelay.c
	$(CC) $(CFLAGS) -o "$@" "$<"


platform_timer.c.o : C:/ProgramData/MATLAB/SupportPackages/R2025b/toolbox/shared/supportpackages/stm32/src/platform_timer.c
	$(CC) $(CFLAGS) -o "$@" "$<"


SysTickScheduler.c.o : $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/SysTickScheduler.c
	$(CC) $(CFLAGS) -o "$@" "$<"


m3m4m4f_multitasking.c.o : $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c
	$(CC) $(CFLAGS) -o "$@" "$<"


main.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_it.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/stm32f4xx_it.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_msp.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/stm32f4xx_hal_msp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_timebase_tim.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/stm32f4xx_hal_timebase_tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_tim.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_tim_ex.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_tim_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_gpio.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_ll_gpio.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_adc.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_ll_adc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_dma.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_ll_dma.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_rcc.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_ll_rcc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_utils.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_ll_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_exti.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_ll_exti.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_rcc.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_rcc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_rcc_ex.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_rcc_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_flash.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_flash.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_flash_ex.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_flash_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_flash_ramfunc.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_flash_ramfunc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_gpio.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_gpio.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_dma_ex.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_dma_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_dma.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_dma.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_pwr.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_pwr.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_pwr_ex.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_pwr_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_cortex.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_cortex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_exti.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_hal_exti.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_spi.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_ll_spi.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_tim.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_ll_tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_usart.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Drivers/STM32F~1/Src/stm32f4xx_ll_usart.c
	$(CC) $(CFLAGS) -o "$@" "$<"


system_stm32f4xx.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/Core/Src/system_stm32f4xx.c
	$(CC) $(CFLAGS) -o "$@" "$<"


syscalls.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/STM32C~1/APPLIC~1/User/Core/syscalls.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sysmem.c.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/STM32C~1/APPLIC~1/User/Core/sysmem.c
	$(CC) $(CFLAGS) -o "$@" "$<"


startup_stm32f405rgtx.s.o : C:/Users/Surinova/ONEDRI~1/DOCUME~1/Github/MATLAB~1/F405_P~1/STM32C~1/APPLIC~1/User/Startup/startup_stm32f405rgtx.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


stm_timer_ll.c.o : C:/ProgramData/MATLAB/SupportPackages/R2025b/toolbox/shared/supportpackages/stm32/src/stm_timer_ll.c
	$(CC) $(CFLAGS) -o "$@" "$<"


#------------------------
# BUILDABLE LIBRARIES
#------------------------

./ssc_sli.lib : $(LIBSSC_SLI_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBSSC_SLI_OBJS)


./ssc_core.lib : $(LIBSSC_CORE_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBSSC_CORE_OBJS)


./pm_st.lib : $(LIBPM_ST_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBPM_ST_OBJS)


./mc.lib : $(LIBMC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBMC_OBJS)


./ex.lib : $(LIBEX_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBEX_OBJS)


./pm.lib : $(LIBPM_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBPM_OBJS)


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### EXESIZE_FLAGS = $(EXESIZE_FLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *.c.dep
	$(RM) *.cpp.dep
	$(RM) *.s.dep
	$(ECHO) "### Deleted all derived files."


