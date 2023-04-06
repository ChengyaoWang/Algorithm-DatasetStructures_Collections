package lc2115

type Node struct {
	is_recipe bool
	cnt       int
	parents   []string
}

func addRecipe(reps *(map[string]*Node), k string, n_ingredients int) bool {
	if _, ok := (*reps)[k]; !ok {
		(*reps)[k] = &Node{}
	}
	(*reps)[k].is_recipe = true
	(*reps)[k].cnt = n_ingredients
	return true
}

func addIngredients(reps *(map[string]*Node), k string, parent string) bool {
	if _, ok := (*reps)[k]; !ok {
		(*reps)[k] = &Node{}
		(*reps)[k].cnt = 1
	}
	(*reps)[k].parents = append((*reps)[k].parents, parent)
	return true
}

func (n *Node) BP(k string, ret *[]string, reps *map[string]*Node) {

	n.cnt -= 1
	if n.cnt == 0 {
		if n.is_recipe {
			(*ret) = append((*ret), k)
		}
		for _, par := range n.parents {
			(*reps)[par].BP(par, ret, reps)
		}
	}
}

func findAllRecipes(recipes []string, ingredients [][]string, supplies []string) []string {

	reps := make(map[string]*Node, 0)
	for i, elem := range recipes {
		addRecipe(&reps, elem, len(ingredients[i]))
		for _, elem_x := range ingredients[i] {
			addIngredients(&reps, elem_x, elem)
		}
	}

	ret := make([]string, 0)
	for _, elem := range supplies {
		if p, ok := reps[elem]; ok {
			p.BP(elem, &ret, &reps)
		}
	}
	return ret
}
