
GCC=g++

OPT=-std=c++11

BUILD_DIR=./build
REDIRECT_BUILD=-o ${BUILD_DIR}

DB_FLAGS=-lsqlite3

UNITTEST_FLAGS=-lgtest_main  -lgtest -lpthread

test: model/algorithm/test/testQuickSort.cpp alg
	${GCC} ${OPT} model/algorithm/test/testQuickSort.cpp ${UNITTEST_FLAGS} ${REDIRECT_BUILD}/unittest.o &&\
	./${BUILD_DIR}/unittest.o

model: model/*.h model/model.cpp alg db
	${GCC} ${OPT} -c model/model.cpp ${REDIRECT_BUILD}/${@}.o

alg: model/algorithm/ISortAlgorithm.h model/algorithm/quickSortAlgorithm.h  model/algorithm/sortAlgorithmFactory.cpp model/algorithm/sortAlgorithmFactory.h
	${GCC} ${OPT} -c model/algorithm/sortAlgorithmFactory.cpp ${REDIRECT_BUILD}/${@}.o

db: model/db/*.h model/db/dbDriverFactroy.cpp
	${GCC} ${OPT} -c model/db/dbDriverFactroy.cpp ${DB_FLAGS} ${REDIRECT_BUILD}/${@}.o

