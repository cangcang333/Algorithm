#!/usr/bin/env python
# coding=utf-8

'''
    Breadth First Search example
'''


# hash table describe the graph
graph = {}
graph["start"] = {}
graph["start"]["a"] = 6
graph["start"]["b"] = 2
print("graph keys is %s" %(graph["start"].keys()))

graph["a"] = {}
graph["a"]["fin"] = 1

graph["b"] = {}
graph["b"]["a"] = 3
graph["b"]["fin"] = 5

graph["fin"] = {}

# cost table
infinity = float("inf")
costs = {}
costs["a"] = 6
costs["b"] = 2
costs["fin"] = infinity

parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["fin"] = None


def find_lowest_cost_node(costs):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        if (cost < lowest_cost and node not in processed):
            lowest_cost = costs
            lowest_cost_node = node

    print("lowest_cost_node is %s" %(lowest_cost_node))
    return lowest_cost_node




processed = []

# 在未处理的节点中找出开销最小的节点
node = find_lowest_cost_node(costs)
# 这个while循环在所有节点都被处理过后结束
while node is not None:
    cost = costs[node]
    neighbors = graph[node]
    # 遍历当前节点的所有邻居
    for n in neighbors.keys():
        print("n is %s" %n)
        new_cost = cost + neighbors[n]
        # 如果经当前节点前往该邻居更近
        if costs[n] > new_cost:
            # 就更新该邻居的开销
            costs[n] = new_cost
            print("costs[n] is %s" %(costs[n]))
            # 同时将该邻居的父节点设置为当前节点
            parents[n] = node
            print("parents[n] is %s" %(parents[n]))

    # 将当前节点标记为处理过
    processed.append(node)
    # 找出接下来要处理的节点，并循环
    node = find_lowest_cost_node(costs)



