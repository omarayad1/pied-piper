from flask import Flask, render_template, url_for, jsonify,request
from parser import register_file, data_memory
import sim
import logging

app = Flask(__name__)

global data

@app.route("/")
def nothing():
    return render_template('PipelineSimulator.html')


@app.route("/registerData", methods=['GET'])
def get_register_data():
	data = []
	for i in xrange(32):
		data.append(register_file.load_from_reg(i))
	return jsonify({"data":data})


@app.route("/memoryData", methods=['GET'])
def get_memory_data():
	data = []
	for i in xrange(32):
		data.append(data_memory.load_word(i))
	return jsonify({"data":data})


@app.route("/simulate", methods=['POST'])
def load_data():
	code = request.form["data"]
	sim.fill_inst_mem(code)
	return "fol"


@app.route("/nextStep", methods=['GET'])
def execute_next_step():
	sim.next_step()
	return "fol"


@app.route("/getLog", methods=['GET'])
def get_log_data():
	data = open('console.log', 'r').read()
	return jsonify({'data': data})


if __name__ == "__main__":
	app.run(debug=True)
