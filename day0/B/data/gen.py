from itertools import cycle
import random
import os
import datetime
import numpy as np

TASK_NUM = 1

N_LIMIT = 100
T_LIMIT = 100
M_LIMIT = 5000

def log(string):
	print(string, flush = True)
	with open("gen.log", "a") as f:
		f.write("[{}] {}\n".format(datetime.datetime.now(), string))

def genRandom(n, t, mlim, no_self_loop = False, even = True):
	if even:
		cnt = [mlim // n] * (n + 1)
	else:
		cnt = [1] * (n + 1)
		i = n
		while i < mlim:
			x = random.randint(1, n)
			if cnt[x] < n:
				cnt[x] += 1
				i += 1
	next_list = [[]]
	nodes = list((range(1, n + 1)))
	if no_self_loop:
		for i in range(1, n + 1):
			while True:
				next_nodes = random.sample(nodes, cnt[i])
				if i not in next_nodes:
					break
			next_list.append(next_nodes)
	else:
		for i in range(1, n + 1):
			next_list.append(random.sample(nodes, cnt[i]))
	return random.randint(1, n), next_list

def genCyclic(n, t, mlim, cycle_len):
	block_list = []
	block_id = [0]
	for i in range(1, cycle_len + 1):
		block_list.append([i])
		block_id.append(i - 1)
	for i in range(cycle_len + 1, n + 1):
		id = random.randint(0, cycle_len - 1)
		block_list[id].append(i)
		block_id.append(id)
	next_list = [[]]
	for i in range(1, n + 1):
		next_id = (block_id[i] + 1) % cycle_len
		next_list.append(random.sample(block_list[next_id], np.random.binomial(len(block_list[next_id]), 0.8)))
	return random.randint(1, n), next_list

def genTree(n, t, mlim, max_delta = N_LIMIT):
	next_list = [[], []]
	for i in range(2, n + 1):
		fa = random.randint(max(i - max_delta, 1), i - 1)
		next_list[fa].append(i)
		next_list.append([])
	for i in range(2, n + 1):
		if len(next_list[i]) == 0:
			next_list[i].append(i)
	return 1, next_list

def genLayered(n, t, mlim, layer_num = 10):
	layer_list = [[]]
	layer_id = [0]
	for i in range(1, layer_num + 1):
		layer_list.append([i])
		layer_id.append(i)
	
	for i in range(layer_num + 1, n + 1):
		id = random.randint(1, layer_num)
		layer_list[id].append(i)
		layer_id.append(id)
	
	layer_list.append([])

	edge_list = []
	next_list = [[]]
	for i in range(1, n + 1):
		candidates = layer_list[layer_id[i]] + layer_list[layer_id[i] + 1]
		x = random.choice(candidates)
		for j in candidates:
			if j == x:
				next_list.append([j])
			else:
				edge_list.append((i, j))
	
	m = min(random.randint(int(len(edge_list) * 0.9), len(edge_list)), mlim - n)

	random.shuffle(edge_list)
	for i in range(m):
		next_list[edge_list[i][0]].append(edge_list[i][1])
	
	return random.choice(layer_list[1]), next_list

def genBlocks(n, t, mlim):
	p = np.random.binomial(n - 1, 0.5)
	nodes = [list(range(1, p + 1)), list(range(p + 1, n + 1))]
	mlim = min(mlim, p ** 2 + (n - p) ** 2)
	cnt = [1] * (n + 1)
	i = n
	while i < mlim:
		x = random.randint(1, n)
		if cnt[x] < (p if x <= p else n - p):
			cnt[x] += 1
			i += 1
	next_list = [[]]
	for i in range(1, p + 1):
		next_list.append(random.sample(nodes[0], cnt[i]))
	for i in range(p + 1, n + 1):
		next_list.append(random.sample(nodes[1], cnt[i]))
	return random.randint(1, n), next_list

def genTestcase(filename, gen, n, t, mlim, **extra_param):
	log("Generating input for case {}, params: {}, {}, {}, {}".format(filename, n, t, mlim, gen.__name__))
	# assert ..., "Parameters invalid!"
	if not extra_param:
		start, next_list = gen(n, t, mlim)
	else:
		start, next_list = gen(n, t, mlim, **extra_param)
	with open("{}.in".format(filename), "w") as f:
		# f.write("{} {} {}\n{}\n".format(n, l, r, " ".join(list(map(str, s)))))
		f.write("{} {} {}\n".format(n, start, t))
		for i in range(1, n + 1):
			f.write(str(len(next_list[i])))
			for j in next_list[i]:
				f.write(" {}".format(j))
			f.write("\n")
	log("Generating output for case {}".format(filename))
	os.system('(time ../infinitesynthesis/std < {}.in > {}.ans) 2>> gen.log'.format(filename, filename))

class Cases:
	def __init__(self, prefix = ""):
		self.cnt = 0
		self.prefix = prefix
	
	def gen(self, gen, n, t, mlim, **extra_param):
		self.cnt += 1
		genTestcase("{}{}".format(self.prefix, self.cnt), gen, n, t, mlim, **extra_param)
	
	def skip(self, cnt = 1):
		self.cnt += cnt

os.system("rm gen.log")
testcase = Cases()
# precase = Cases("../pre/")
sample = Cases("../down/")

for i in range(1, TASK_NUM + 1):
	log("Generating subtask {}".format(i))
	pre = testcase.cnt
	# pre_pre = precase.cnt
	# add testcases below
	
	testcase.gen(genRandom, N_LIMIT, T_LIMIT, M_LIMIT)
	for i in range(2):
		testcase.gen(genRandom, N_LIMIT - random.randint(0, 1), T_LIMIT - random.randint(0, 1), M_LIMIT - random.randint(0, 1))
	
	for i in range(2):
		testcase.gen(genCyclic, N_LIMIT, T_LIMIT, M_LIMIT, cycle_len = 2)
	
	for i in range(2):
		testcase.gen(genCyclic, N_LIMIT, T_LIMIT, M_LIMIT, cycle_len = random.randint(3, 12))
	
	for i in range(2):
		testcase.gen(genTree, N_LIMIT - random.randint(0, 1), T_LIMIT - random.randint(0, 1), M_LIMIT)
	
	for i in range(2):
		testcase.gen(genLayered, N_LIMIT, T_LIMIT, M_LIMIT, layer_num = random.randint(5, 15))
	
	testcase.gen(genBlocks, N_LIMIT, T_LIMIT, M_LIMIT)
	
	# add testcases above		
	log("Subtask {} done. ({} - {})".format(i, pre + 1, testcase.cnt))
	# log("Subtask {} done. (test: {} - {}; pre: {} - {})".format(i, pre + 1, testcase.cnt, pre_pre + 1, precase.cnt))

sample.skip(2)
sample.gen(genRandom, 100, 100, 600, no_self_loop = True, even = True)

# for duck
# os.system("mkdir download")
# os.system("cp ../down/* ./download/")
