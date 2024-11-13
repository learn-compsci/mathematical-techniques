```javascript
function swap(list, idx1, idx2) {
    temp = list[idx1];
    list[idx1] = list[idx2];
    list[idx2] = temp;
}

function partition(list, start_idx, end_idx) {

	// randomly pick a pivot from list[start_idx, end_idx)
	// and swap it with the last element
	swap(list, end_idx - 1, rand_int(start_idx, end_idx));

	// set the last element as the pivot value
	pivot_value = list[end_idx - 1]
	partition_idx = 0

	// (1) we to maintain that [start_idx, partition_idx) contains elements
	// <= pivot_value

	// (2) we also want to maintain that [pivot_idx, curr_idx) contains
	// elements that are > pivot_value

	for(curr_idx = start_idx; curr_idx < end_idx - 1; curr_idx += 1) {
		// if the element at curr_idx is smaller than pivot_value;
		// to maintain invariant (1)
		if(list[curr_idx] <= pivot_value) {
			swap(list, curr_idx, partition_idx);
		}
		// otherwise, since the current item was > pivot_value
		// we just have to increment 
		// curr_idx to maintain invariant (2)
	}

	// after this is done, since curr_idx == end_idx - 1
	// we know that:
	// (1) [start_idx, partition_idx) contains elements <= pivot_value
	// and 
	// (2) [partition_idx, end_idx - 1) contains elements > pivot_value

	swap(list, partition_idx, end_idx - 1);
	// now after we do the swap:
	// we know that:
	// (1) [start_idx, partition_idx] contains elements <= pivot_value
	// and 
	// (2) [partition_idx + 1, end_idx - 1] contains elements > pivot_value
	// Why? because pivot_value = pivot_value and now it's on partition_idx.
	// so the intervals have changed.
	// In particular, the previous element before the swap at partition_idx
	// was > pivot_value. it is now sitting at end_idx - 1 after the swap
	return partition_idx;
}

function quicksort(list, start_idx, end_idx) {
	if(start_idx >= end_idx) {
		return;
	}
    partition_idx = partition(list, start_idx, end_idx);
	// we are now guaranteed that:
	// list[start_idx, partition_idx) has values <= list[partition_idx]
	// and
	// list(partition_idx, end_idx) has values > list[parition_idx]
    quicksort(list, start_idx, partition_idx);
    quicksort(list, partition_idx + 1, end_idx);
}
```