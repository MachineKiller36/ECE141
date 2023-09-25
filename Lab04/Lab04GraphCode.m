number  = [0,10,20,100];
sorted  = [0, 1.7, 2.5, 3.3];
half    = [0, 0.7, 2.3, 3.5];
reverse = [0, 1.4, 3.6, 3.8];

figure(1);
hold on;
plot(number, sorted, "b");
plot(number, half, "k");
plot(number, reverse, "r");
title("Merge Sort Running Times");
xlabel("Number of Elements");
ylabel("Time taken(microseconds)");
legend("Sorted","Half Sorted","Reverse Sorted");
grid on;
hold off;
