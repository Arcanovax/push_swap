from random import randint
# from random import shuffeu
def gen_lst(nb_value=500, mini=0, maxi=9999):
	assert mini < maxi
	lst = set()
	while len(lst) < nb_value:
		lst.add(str(randint(mini, maxi)))
	return " ".join(lst)

print(gen_lst(500, 0, 9999))