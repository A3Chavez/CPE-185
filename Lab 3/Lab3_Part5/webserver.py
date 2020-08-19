from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/major/<name>')
def major(name):
	return render_template('page.html', name='Computer Engineering (CPE)')

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port='5000')
