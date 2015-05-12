from flask import Flask, render_template, url_for, jsonify
from parser import register_file

app = Flask(__name__)


@app.route("/")
def nothing():
    return render_template('PipelineSimulator.html')

@app.route("/registerData", methods=['GET'])
def get_register_data():
	data = []
	for i in xrange(32):
		data.append(register_file.load_from_reg(i))
	print data
	return jsonify({"data":data})
if __name__ == "__main__":
	app.run(debug=True)
