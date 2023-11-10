clf;
load vs 
hold on;
plot(vs(:,1),vs(:,2)),'b';
plot(vs(:,1),vs(:,3),'r')
legend('ve')
xlabel('t (s)')
ylabel('vs (V)')
axis([0 pi -1 1])
title('source vs(t)')