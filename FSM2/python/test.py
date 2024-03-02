from solution import Solution

hsi_in = open('../tests/hsi_in.txt', 'r')
hsi_lines_in = hsi_in.readlines()

hsi_out = open('../tests/hsi_out.txt', 'r')
hsi_lines_out = hsi_out.readlines()

for i in range(0, len(hsi_lines_out)):
    hsi_lines_out[i] = hsi_lines_out[i].strip() + " "

tour_in = open('../tests/tour_in.txt', 'r')
tour_lines_in = tour_in.readlines()

tour_out = open('../tests/tour_out.txt', 'r')
tour_lines_out = tour_out.readlines()

for i in range(0, len(tour_lines_out)):
    tour_lines_out[i] = tour_lines_out[i].strip() + " "

def hsi_generator(Class):
    def test():
        sol = Class()
        for i in range(0, len(hsi_lines_in)):
            res = sol.RunAndReset(hsi_lines_in[i])
            assert(res == hsi_lines_out[i])
    return test

def tour_generator(Class):
    def test():
        sol = Class()
        for i in range(0, len(tour_lines_in)):
            res = sol.RunAndReset(tour_lines_in[i])
            assert(res == tour_lines_out[i])
    return test

# test_solution_tour = tour_generator(Solution)

test_solution_hsi = hsi_generator(Solution)
