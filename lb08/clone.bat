git clone https://github.com/Path0/Vocareum && cd ./Vocareum && cd ./lb08 && cp -f lb08.c ./../../lb08.c && cd ~ && rm -r -f ./Vocareum

git clone https://github.com/Path0/Vocareum && cd ./Vocareum && cd ./lb08 && cp -f lb08.c ./../../lb08.c && cd ~ && rm -r -f ./Vocareum && gcc lb08.c && ./a.out


echo 'git clone https://github.com/Path0/Vocareum && cd ./Vocareum && cd ./lb08 && cp -f lb08.c ./../../lb08.c && cd ~ && rm -r -f ./Vocareum' >> clone && chmod +x clone && ./clone && echo 'gcc lb08.c && ./a.out' >> run && chmod +x run