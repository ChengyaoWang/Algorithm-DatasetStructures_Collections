package lc1844

func replaceDigits(s string) string {
	arr := []byte(s)
	for i := 1; i < len(arr); i += 2 {
		arr[i] = arr[i-1] + (arr[i] - '0')
	}
	return string(arr)
}
