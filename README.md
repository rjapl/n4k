# n4k
node module for k9

* Summary

node relies on V8(C++, where there is no up-to-date and stable C wrapper yet). I tried napi, nan and addon api. The addon api is easiest to use, less boiler plated and less V8 API related.

 

* Setup
OS: Ubuntu 18.04.4 LTS

apt-get install nodejs-dev

git clone https://github.com/nodejs/node-addon-api.git # or use npm to install node-addon-api to your source code dir

No other build env dependencies except g++

 

* Build and test

g++ -shared -pthread -rdynamic -m64 -I. -I/usr/include/nodejs/include/node -I/usr/include/nodejs/src -I/usr/include/nodejs/deps/uv/include -I/usr/include/nodejs/deps/v8/include -I/YOUR_PATH_node_addon/node-addon-api -fPIC -pthread -m64 -O3 -fno-omit-frame-pointer -fno-rtti -o nn.so.node nn.cc _.so

node --no-warnings
> v1=require('./nn.so.node').k("+",[2,2.3])
4.3
> v1
4.3
> console.log(v1)
4.3
undefined
> typeof v1
'number'
