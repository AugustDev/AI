NAME = 'AI'
SRC = src
TGT = obj
PRG = application
INCLUDES = -Iinclude -I /usr/lib/jvm/java-7-openjdk-amd64/include/
LIBRARIES = -L /usr/lib/jvm/java-7-openjdk-amd64/jre/lib/amd64/server/
CXXFLAGS = -O2 -std=c++0x $(INCLUDES) $(LIBRARIES)
SOURCES = $(wildcard $(SRC)/*.cpp) $(wildcard $(SRC)/*/*.cpp)
ENDFLAGS = -ljvm -lcurl
NOWARNINGS = -Wno-unused-variable -Wno-unused-result
OBJS = $(addprefix $(TGT)/, $(notdir $(SOURCES:.cpp=.o)))

$(TGT)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(NOWARNINGS)

$(TGT)/%.o: $(SRC)/Modules/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(NOWARNINGS)

$(PRG)/$(NAME): $(OBJS)
	$(CXX) $(LIBRARIES) $(OBJS) -o $@ $(ENDFLAGS) $(NOWARNINGS)

clean:
	rm obj/*.o
