# Historial de versiones
# 2.0 (17/03/2020): corregido un error que hacía que la práctica no se recompilara para algunos ficheros de prueba
#

# Recorrer carpetas que comiencen por "PRUEBA"
for DIR in PRUEBA*; do
    if [ -d "$DIR" ]; then
        for FILE in $DIR/tad*.cpp ; do 
            echo "Evaluando $FILE"
            
            cp $FILE src/tad.cpp 
            rm -f ./tad
            make
            
            ./tad > $FILE.out
            diff -b -B -i $FILE.out $FILE.sal
            
            if [ "$?" == "0" ]; then
                echo "OK"
            else
                echo "ERROR"
            fi
        done
    fi
done

