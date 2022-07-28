# build 
```
docker build --build-arg UID="$(id -u)" --build-arg GID="$(id -g)" --build-arg UNAME="$(whoami)" . -t cpp
```

# executar o container para acessar o bash
```
docker run -it --rm -v `pwd`:/usr/src/codigos cpp
```

# compilando no container

```
gcc -o build/Conversor src/Conversor.cpp
```

# rodando o programa no container
```
./build/Conversor
```