from distutils.core import setup, Extension

extension_mod = []
extension_mod.append(Extension("_add", ["native/add_wrap.cxx", "native/add.cpp", "native/rtype.cpp", "native/instruction.cpp", "native/PC.cpp", "native/regfile.cpp"]))
extension_mod.append(Extension("_regfile", ["native/regfile_wrap.cxx", "native/regfile.cpp"]))
extension_mod.append(Extension("_PC", ["native/PC_wrap.cxx", "native/PC.cpp"]))
extension_mod.append(Extension("_XOR", ["native/XOR_wrap.cxx", "native/XOR.cpp", "native/rtype.cpp", "native/instruction.cpp", "native/PC.cpp", "native/regfile.cpp"]))
extension_mod.append(Extension("_addi", ["native/addi_wrap.cxx", "native/addi.cpp", "native/itype.cpp", "native/instruction.cpp", "native/data_mem.cpp", "native/regfile.cpp"]))
extension_mod.append(Extension("_jal", ["native/jal_wrap.cxx", "native/jal.cpp", "native/jtype.cpp", "native/instruction.cpp", "native/data_mem.cpp", "native/regfile.cpp", "native/PC.cpp"]))
extension_mod.append(Extension("_jr", ["native/jr_wrap.cxx", "native/jr.cpp", "native/rtype.cpp", "native/instruction.cpp", "native/data_mem.cpp", "native/regfile.cpp", "native/PC.cpp"]))

extension_mod.append(Extension("_ble", ["native/ble_wrap.cxx","native/ble.cpp" ,"native/itype.cpp", "native/instruction.cpp", "native/data_mem.cpp", "native/regfile.cpp"]))
extension_mod.append(Extension("_bne", ["native/bne_wrap.cxx", "native/bne.cpp", "native/itype.cpp", "native/instruction.cpp", "native/data_mem.cpp", "native/PC.cpp", "native/regfile.cpp"]))
extension_mod.append(Extension("_data_mem", ["native/data_mem_wrap.cxx", "native/data_mem.cpp"]))
extension_mod.append(Extension("_instr_mem", ["native/instr_mem_wrap.cxx", "native/instr_mem.cpp"]))
extension_mod.append(Extension("_instruction", ["native/instruction_wrap.cxx", "native/instruction.cpp"]))

extension_mod.append(Extension("_itype", ["native/itype_wrap.cxx", "native/itype.cpp", "native/instruction.cpp", "native/data_mem.cpp"]))
extension_mod.append(Extension("_jtype", ["native/jtype_wrap.cxx", "native/jtype.cpp", "native/instruction.cpp", "native/PC.cpp"]))
extension_mod.append(Extension("_jump", ["native/jump_wrap.cxx", "native/jump.cpp", "native/jtype.cpp", "native/instruction.cpp", "native/PC.cpp"]))
extension_mod.append(Extension("_load", ["native/load_wrap.cxx", "native/load.cpp", "native/itype.cpp", "native/instruction.cpp", "native/data_mem.cpp", "native/regfile.cpp"]))

extension_mod.append(Extension("_pipe_line", ["native/pipe_line_wrap.cxx", "native/pipe_line.cpp", "native/itype.cpp", "native/jtype.cpp", "native/rtype.cpp", "native/instruction.cpp", "native/data_mem.cpp", "native/PC.cpp", "native/regfile.cpp"]))
extension_mod.append(Extension("_regfile", ["native/regfile_wrap.cxx", "native/regfile.cpp"]))
extension_mod.append(Extension("_rtype", ["native/rtype_wrap.cxx", "native/rtype.cpp", "native/instruction.cpp", "native/PC.cpp", "native/regfile.cpp"]))
extension_mod.append(Extension("_slt", ["native/slt_wrap.cxx", "native/slt.cpp", "native/rtype.cpp", "native/instruction.cpp", "native/PC.cpp", "native/regfile.cpp"]))
extension_mod.append(Extension("_store", ["native/store_wrap.cxx", "native/store.cpp", "native/itype.cpp", "native/instruction.cpp", "native/data_mem.cpp", "native/regfile.cpp"]))
setup(name = "pied-piper", ext_modules=extension_mod)