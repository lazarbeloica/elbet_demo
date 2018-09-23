
GCC=g++

OPT=-std=c++11

BUILD_DIR=./build
REDIRECT_BUILD=-o ${BUILD_DIR}

OGL_FLAGS=-L/usr/X11R6/lib -lglut -I/usr/X11R6/include -L./3pp/glui/lib -lglui -lGL -lGLU

DB_FLAGS=-lsqlite3

UNITTEST_FLAGS=-lgtest_main  -lgtest -lpthread

all: test ui model alg db main.cpp controller
	${GCC} ${OPT} main.cpp ${BUILD_DIR}/ui.o ${BUILD_DIR}/alg.o ${BUILD_DIR}/db.o ${BUILD_DIR}/controller.o ${BUILD_DIR}/model.o ${DB_FLAGS} ${OGL_FLAGS} ${REDIRECT_BUILD}/elbet

test: model/algorithm/test/testQuickSort.cpp alg
	${GCC} ${OPT} model/algorithm/test/testQuickSort.cpp ${UNITTEST_FLAGS} ${REDIRECT_BUILD}/unittest.o &&\
	./${BUILD_DIR}/unittest.o

controller: controller/controller.h controller/controller.cpp
	${GCC} ${OPT} -c controller/controller.cpp ${REDIRECT_BUILD}/${@}.o
ui: ui/ui.cpp ui/*.h
	${GCC} ${OPT} -c ui/ui.cpp ${OGL_FLAGS} ${REDIRECT_BUILD}/${@}.o

model: model/*.h model/model.cpp alg db
	${GCC} ${OPT} -c model/model.cpp ${REDIRECT_BUILD}/${@}.o

alg: model/algorithm/ISortAlgorithm.h model/algorithm/quickSortAlgorithm.h  model/algorithm/sortAlgorithmFactory.cpp model/algorithm/sortAlgorithmFactory.h
	${GCC} ${OPT} -c model/algorithm/sortAlgorithmFactory.cpp ${REDIRECT_BUILD}/${@}.o

db: model/db/*.h model/db/dbDriverFactroy.cpp
	${GCC} ${OPT} -c model/db/dbDriverFactroy.cpp ${DB_FLAGS} ${REDIRECT_BUILD}/${@}.o ;\
	`cp 3pp/db/elbet.db ${BUILD_DIR}`

