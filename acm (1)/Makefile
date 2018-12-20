
name=a
f=-g

run: $(name)
	./$(name)

in: $(name)
	./$(name) < $(name).in

out: $(name)
	./$(name) > $(name).out

io: $(name)
	./$(name) < $(name).in > $(name).out

$(name): $(name).cpp
	g++ $(f) -std=c++11 $(name).cpp -o $(name)
