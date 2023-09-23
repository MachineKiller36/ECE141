number = [0 10 50 100];
select_sorted =[0 0.8 1.9 5.1];
select_half = [0 0.4 2.1 5.4];
select_reversed = [0 0.4 1.9 5.8];

% Plots all of Selection Sort conditions
figure(1);
hold on;
plot(number,select_sorted,"b");
plot(number,select_half,"k");
plot(number,select_reversed,"r");
axis([0 100 0 40]);
title("Selection Sort Running Time");
xlabel("Number of elements inserted");
ylabel("Time (microseconds)");
legend("Sorted", "Half-Sorted","Reversed Sorted");
grid on;
hold off;

% Plots all of Bubble Sort conditions
bubble_sorted = [0 0.2 4.4 12.4];
bubble_half = [0 0.1 6.3 21.9];
bubble_reversed = [0 0.2 11.9 42.9];
figure(2);
hold on;
plot(number, bubble_sorted,"b");
plot(number,bubble_half,"k");
plot(number,bubble_reversed,"r");
axis([0 100 0 45]);
title("Bubble Sort Running Time");
xlabel("Number of elements inserted");
ylabel("Time (microseconds)");
legend("Sorted","Half-Sorted","Reversed Sorted");
grid on;
hold off;

% Plots the reverse condition for Selection Sort and Bubble Sort
figure(3);
hold on;
plot(number,select_reversed,"b");
plot(number,bubble_reversed,"r");
axis([0 100 0 45]);
grid on;
title("Selection Sort vs. Bubble Sort Worst Case");
xlabel("Number of elements inserted");
ylabel("Time (microseconds)");
legend("Selection Sort", "Bubble Sort");
hold off;