all:
	swig -c++ -python native/regfile.i
	swig -c++ -python native/add.i
	swig -c++ -python native/addi.i
	swig -c++ -python native/PC.i
	swig -c++ -python native/XOR.i
	swig -c++ -python native/addi.i
	swig -c++ -python native/ble.i
	swig -c++ -python native/bne.i
	swig -c++ -python native/data_mem.i
	swig -c++ -python native/instr_mem.i
	swig -c++ -python native/instruction.i
	swig -c++ -python native/itype.i
	swig -c++ -python native/jal.i
	swig -c++ -python native/jr.i
	swig -c++ -python native/jtype.i
	swig -c++ -python native/jump.i
	swig -c++ -python native/load.i
	swig -c++ -python native/pipe_line.i
	swig -c++ -python native/regfile.i
	swig -c++ -python native/rtype.i
	swig -c++ -python native/slt.i
	swig -c++ -python native/store.i
	swig -c++ -python native/ret.i
	swig -c++ -python native/end.i
	python setup.py build_ext --inplace
	touch native/__init__.py

linux:
	make all

clean:
	rm -rf native/*.cxx
	rm -rf native/*.py
	rm -rf build