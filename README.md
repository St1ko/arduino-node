# arduino-node
Node application that connects arduino to a webpage

## Requirements

* Node.js
* NPM / Yarn

### Node.js installation
To install Node.js and NPM go to the [official Node.js website](https://nodejs.org/) and download the installer or run the following commands in your command line.

    $ sudo apt install nodejs
    $ sudo apt install npm

You can verify your installation by running the following commands.

    $ node --version
    v12.12.0
    
    $ npm --version
    6.9.0
    
### Yarn installation
To install Yarn, run the following command in your command line.

    $ npm install -g yarn
    
&nbsp;

## Local development
Clone this repository to you local machine by running the following command in your command line.

    $ git clone https://github.com/St1ko/arduino-node
    
### Installing app dependencies
Now go to the project directory and install the apps dependencies.

    $ cd arduino-node
    $ yarn

### Running the app
To start the application run the following command. This will start up the node server which connects to the arduino and serves the web page.

    $ node script.js
    
Go to `http://localhost:3000` to view the application that is running on your local machine.

&nbsp;


## Built With

* [Node.js](https://nodejs.org/en/)
* [Express](https://expressjs.com/)
* [Socket.IO](https://socket.io/)

## Authors

* **Stijn Albert** - [St1ko](https://github.com/St1ko)
* **Eva Kaper** - [Appelszijnvies](https://github.com/Appelszijnvies)
* **Thijs de Veth** - [tdeveth](https://github.com/tdeveth)
