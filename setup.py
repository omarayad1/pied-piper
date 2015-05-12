from distutils.core import setup, Extension

extension_mod1 = Extension("_add", ["native/add_wrap.cxx", "native/add.cpp", "native/rtype.cpp", "native/instruction.cpp", "native/PC.cpp", "native/regfile.cpp"])
extension_mod2 = Extension("_regfile", ["native/regfile_wrap.cxx", "native/regfile.cpp"])

setup(name = "pied-piper", ext_modules=[extension_mod1,extension_mod2])