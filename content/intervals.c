#include <cs1010.h>
#include <assert.h>

long get_ith_start(long const *const intervals, size_t i) {
    return intervals[2 * i];
}
long get_ith_end(long const *const intervals, size_t i) {
    return intervals[2 * i + 1];
}

void set_ith_start(long *intervals, size_t i, long value) {
    intervals[2 * i] = value;
}

void set_ith_end(long *intervals, size_t i, long value) {
    intervals[2 * i + 1] = value;
}

void print_interval(long start, long end){
    cs1010_print_string("[");
    cs1010_print_long(start); 
    cs1010_print_string(",");
    cs1010_print_long(end); 
    cs1010_println_string("]");
}

void get_interval(long *intervals, size_t num_intervals) {
    size_t merged_size = 0;
    long *merged_list = calloc(2 * num_intervals, sizeof(long));
    

    for(size_t idx = 0; idx < num_intervals; idx += 1) { 
        // now we compare the current element against the top of the stack
        long current_start = get_ith_start(intervals, idx);
        long current_end = get_ith_end(intervals, idx);

        while(merged_size > 0 && current_start < get_ith_start(merged_list, merged_size - 1)) {
            merged_size -= 1;
        }

        if(merged_size == 0) {
            set_ith_start(merged_list, 0, current_start);
            set_ith_end(merged_list, 0, current_end);
            merged_size = 1;
        } else if(get_ith_end(merged_list, merged_size - 1) < current_start) {
            // the previous interval ends before ours starts, so we should just add a new interval to the list
            set_ith_start(merged_list, merged_size, current_start);
            set_ith_end(merged_list, merged_size, current_end);
            merged_size += 1;
        } else if(get_ith_end(merged_list, merged_size - 1) < current_end) {
            // else there is an interval that ends after we start.
            // and from the while loop we are guaranteed, it starts before we do
            // now we also know we end before it.
            set_ith_end(merged_list, merged_size - 1, current_end);
        } // otherwise we know current_end is before the end of the last interval on merged_list
        // in that case we do not do anything
    }


    for(size_t idx = 0; idx < merged_size; idx += 1){
        print_interval(get_ith_start(merged_list, idx), get_ith_end(merged_list, idx));        
    }
    
    free(merged_list);
    
}

int main(){
    size_t num_intervals = cs1010_read_size_t();
    long *intervals = cs1010_read_long_array(num_intervals * 2); 
    get_interval(intervals, num_intervals);
    free(intervals);
}
