from random import randint
# from random import shuffeu
def gen_lst(nb_value, mini=250, maxi=250):
	assert mini < maxi
	lst = set()
	while len(lst) < nb_value:
		lst.add(str(randint(mini, maxi)))
	return " ".join(lst)

print(gen_lst(100, 0, 9999))