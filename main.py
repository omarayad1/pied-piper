from flask import Flask, render_template, url_for
app = Flask(__name__)


@app.route("/")
def nothing():
    return render_template('PipelineSimulator.html')

if __name__ == "__main__":
	app.run(debug=True)
