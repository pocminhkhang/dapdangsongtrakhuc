# ĐẬP DÂNG SÔNG TRÀ KHÚC
Dự án vận hành mô hình đập dâng sông Trà Khúc - Quảng Ngãi

Lĩnh vực dự thi:
-	Phần mềm tin học.
-	Các giải pháp kỹ thuật nhằm ứng phó với biến đổi khí hậu, bảo vệ môi trường và phát triển kinh tế

Giáo viên hướng dẫn:
    Lê Thị Như Huyền 
    SĐT: 0935745789
Tác giả:				Lớp:
    Trần Hoàng Minh Khánh	7B4
    Trần Hoàng Minh Khang	7B4
    Hoàng Minh Tuấn		7B4

A.	Ý TƯỞNG:
Nhiều lần cả nhà đi biển, ba em giới thiệu đập dâng và giải thích công dụng của nó. Anh em chúng em rất hứng thú, mong muốn được thấy nước sông dâng lên sẽ rất đẹp. Chờ đợi cũng lâu nhưng chưa thấy đập dâng hoạt động, thành phố Quảng Ngãi vào mùa nắng trơ trọi lòng sông, vậy là 3 anh em chúng em rủ nhau thực hiện dự án vận hành nó (đập dâng sông Trà Khúc)
Ban đầu chúng em chỉ nghĩ đến việc vận hành ngăn nước, xả nước sao cho nước dâng lên – hạ xuống như mong muốn là được. Tuy nhiên trong quá trình tìm hiểu thì mọi chuyện không đơn giản như vậy, trong các video em tìm hiểu được trên mạng về các con đập lớn, người ta đã phải làm cầu cá nhằm đảm bảo tính tự nhiên của hệ sinh thái dòng sông, do vậy đập dâng mô hình phải có cầu cá cho cá bơi ngược dòng về thượng nguồn, đập dâng phải vận hành hoàn toàn tự động theo mực nước thượng nguồn, điều tiết dòng chảy xuống hạ lưu làm sao để không bị nước biển xâm nhập, …
B.	CẤU TẠO MÔ HÌNH SẢN PHẨM
I.	Nguyên vật liệu làm mô hình:

	Tên vật tư	ĐVT	SL	Đơn giá	Thành tiền	Ghi chú
1	Tấm nền (40x80)	Cái	1	100,000 	100,000 	 
2	Sốp dùng làm bờ sông, núi	Tấm	5	20,000 	100,000 	 
3	Làm các phần của đập dâng	Bộ	5	20,000 	100,000 	 
4	Cảm biến mưa	Bộ	1	26,000 	26,000 	 
5	Cảm biến JDS	Bộ	1	81,000 	81,000 	 
6	Cảm biến khoảng cách	Bộ	3	32,000 	96,000 	 
7	Công tắt	Cái	1	2,000 	2,000 	 
8	Servo MG90S	Cái	4	35,000 	140,000 	 
9	Màn hình HMI 2.8inch cảm ứng tích hợp chip ESP32	Cái	1	260,000 	260,000 	 
10	Mạch mở rộng I2C	Cái	1	12,000 	12,000 	 
11	Cầu cá	Cái	1	30,000 	30,000 	 
12	Chip lập trình nhúng ESP32	Cái	1	  88,000 	88,000 	
13	Pin 18650	Cái	1	36,000 	36,000 	 
14	Mạch sạc pin 18650	Cái	1	16,000 	16,000 	 
-	Tổng tiền chi phí nguyên vật liệu: 1.087.000 đ
II.	 Cách lắp ráp, lắp đặt sản phẩm
1.	Mô hình núi, dòng sông, biển:
-	Núi: Làm từ sốp, đắp nhiều lớp lên rồi dùng dao gọt, tạo hình ngọn núi.
-	Bờ sông: Dùng sốp đắp dọc theo 2 bờ tấm nền để tạo bờ sông, hình thành lòng sông và biển ở cuối dòng.
-	Thời gian hoàn thành: 5 ngày
2.	Đảo Ngọc:
-	Dùng sốp làm hòn đảo giữ dòng sông, mô phỏng theo hình Đảo Ngọc thực tế.
-	Thời gian hoàn thành: 1 ngày
3.	Mô hình đập dâng:
-	Đập dâng được làm từ sốp dựng 4 trụ cao, lắp 2 tấm nhựa làm mô hình tấm chắn nước được cắm vào trụ đập.
-	Gắn 3 servo Mg290s vào các trụ như mô hình, 2 servo móc vào 2 tấm nhựa chắn nước, servo còn lại gắn vào mô hình cầu cá
-	Thời gian hoàn thành: 5 ngày
4.	Mô hình cầu cá: 
-	Mô hình cầu cá được làm từ sốp, tạo các bậc thang từ trên xuống dưới, khoét tạo hộc chứa nước, tạo hướng nước chảy 2 bên
-	Thời gian hoàn thành: 3 ngày
5.	Thiết bị đo mực nước:
-	Thiết bị đo mực nước sử dụng cảm biến đo khoảng cách, được cắm vào chip lập trình nhúng ESP32 Dev module và lâp trình để đo khoảng cách từ đầu dò đến mực nước hiện tại và đưa dữ liệu lên đám mây blynk
-	Cảm biến đo khoảng cách dựa vào sóng âm phát ra và thời gian nhận sóng dội âm, từ đó tính toán ra khoảng cách từ đầu dò đến mặt nước. Cảm biến được cắm vào chip lập trình nhúng và được lập trình để đưa số liệu lên đám mây blynk. Trong dự án có 3 đầu dò chiều cao mực nước, các đầu dò được bố trí, đặt tên khác nhau vì thế số liệu từng đầu dò được đưa lên đám mây blynk độc lập nhau.
-	Thời gian hoàn thành: 5 ngày
6.	Thiết bị dò mưa: 
-	Thiết bị báo mưa sử dụng cảm biến mưa cắm vào chip lập trình nhúng ESP32 Dev module và lập trình để đưa số liệu lên đám mây blynk
-	Thiết bị do điện trở của tấm cảm biến, nếu điện trở giảm là do mưa. Chip lập trình đọc giá trị của cảm biến và lưu trên blynk.
-	Thời gian hoàn thành: 2 ngày
7.	Thiết bị đo độ mặn: 
-	Thiết bị đo độ mặn dùng cảm biến TDS cắm vào chip lập trình nhúng ESP32 Dev module và lập trình để đưa số liệu lên đám mây blynk.
-	Thiết bị đo độ mặn của nước đo chỉ số dẫn điện của muối hòa tan trong nước, số liệu đo được sẽ được cập nhật lên đám mây blynk.
-	Thời gian hoàn thành: 2 ngày
8.	Hệ thống điều khiển trung tâm
-	Hệ thống điều khiển trung tâm là màn hình điều khiển HMI LVGL ESP32 WROOM 2.8inch cảm ứng: Màn hình điều khiển tích hợp chip ESP32 lập trình nhúng, một bộ điều khiển gọn nhẹ.
-	Hệ thống điều khiển trung tâm được lập trình để lấy số liệu từ đám mây blynk mà các thiết bị gởi lên để làm số liệu đầu vào nhằm tính toán đưa ra quyết định vận hành đóng – mở cửa xả nước ở cao độ bao nhiêu, đảm bảo mực nước trên và dưới đập dâng đạt yêu cầu, nâng hạ cầu cá để cho cá được đi chuyển thuận lợi nhất.
-	Thời gian hoàn thành: 15 ngày
III.	Nguyên tắc hoạt động, vận hành của mô hình đập dâng
1.	Hệ thống số liệu vận hành của đập dâng:
-	Mực nước mong muốn đạt được theo mùa, hoặc theo biểu đồ độ cao theo thời gian, hoặc theo yêu cầu thực tế vận hành theo số liệu nhập vào.
-	Số liệu nhận được từ các đầu dò được bố trí dọc theo sông: 
+	Đầu dò mưa được bố trí ở thượng nguồn sông, viết tắt: MUA
+	Đầu dò chiều cao mực nước thượng nguồn, viết tắt: MT
+	Đầu dò chiều cao mực nước tại đập dâng, viết tắt: MD
+	Đầu dò chiều cao mực nước tại hạ nguồn, viết tắt: MH
+	Đầu dò độ mặn nước sông hạ nguồn, viết tắt: MAN
-	Thiết lập giá trị mô phỏng vận hành:
+	Có mưa (MUA = 1), không mưa (MUA = 0)
+	Mực nước cao (MTH = 10), bình thường (MTO = 5), thấp tại thượng nguồn (MTL = 0)
+	Mực nước cao (MDH = 10), bình thường (MDO = 5), thấp tại đập dâng (MDL = 0)
+	Mực nước cao (MHH = 10), bình thường (MHO = 5), thấp tại hạ nguồn (MHL = 0)
+	Độ mặn cao (MANH = 10), bình thường (MANO = 5), thấp tại hạ nguồn (MANL = 0)
2.	Điện toán đám mây trung gian:
-	Các đầu dò, cảm biến, đập dâng, tủ điều khiển ở khoảng cách vật lý xa nhau, do vậy để chúng giao tiếp được với nhau thì phải sử dụng wifi, thiết bị sẽ kết nối wifi, đưa số liệu đo đạc được lên đám mây blynk.
-	Bằng cách tạo tài khoản tại blynk, đám mây blynk hỗ trợ tạo các đối tượng dữ liệu nhập vào, lưu tạm, từ đó tủ điều khiển trung tâm có thể truy xuất dữ liệu bất cứ lúc nào để vận hành hệ thống
3.	Nguyên tắc vận hành tự động:
-	Thiết lập cao độ của cầu cá thấp hơn giá trị đầu dò MD 10 cm, tạo dòng chảy êm cho cầu cá, MD thay đổi thì độ cao của cầu cá thay đổi theo.
-	Hệ thống liên tục cập nhật số liệu từ các cảm biến dọc theo sông, lấy mực nước tại đập dâng làm trung tâm cho kịch bản vận hành, từ đó đưa ra quyết định mở đập được tính như sau: 
+	Lưu lượng cần xả hoặc đóng = (MD – MDO) x (hệ số k) x (hệ số quy đổi ra lưu lượng nước cần xả hay đóng dựa trên mong muốn triệt tiêu chênh lệch nhanh hay chậm)
+	Hệ số k là hệ số dùng để tính tỉ lệ điều chỉnh chiều cao mực nước được làm theo thuật toán PID, nhưng do chúng em chưa học đạo hàm và tích phân nên chỉ hiện chỉ dùng tỉ lệ điều chỉnh.
+	Giá trị mặc định cho hệ số k = 2, nghĩa là hệ thống sẽ nâng tốc độ xả hay đóng gấp 2 lần độ chênh lệch mực nước tại đập dâng.
+	Mực nước thượng nguồn MT điều chỉnh hệ số k như sau:
hệ số k = hệ số k + (MT - MTO)/MTO
Khi đó nếu MT > MTO thì hệ số k được cộng thêm, ngược lại sẽ bị trừ đi
+	Trong điều kiện có mưa ở thượng nguồn thì:
hệ số k = hệ số k + 0.01
Khi đó nếu trời có mưa thì việc mở đập sẽ được tác động thêm 0.01. Hệ số 0.01 này chưa được tính chính xác mà chỉ là giả lập, cần tính toán lại theo điều kiện thực tế để có số liệu chính xác hơn.
+	Trong điều kiện hạ nguồn quá cạn nước (MHO - MH) >=4 thì hệ thống sẽ phát thông báo cảnh báo đến người điều hành ra quyết định can thiệp hay không.
+	Trong điều kiện hạ nguồn bị ngập mặn cao (MANH - MAN) <=2 thì hệ số k được tính:
hệ số k = hệ số k + 5%
Việc bù số % bao nhiêu khi ngập mặn cần được tính toán theo số liệu thực tế dòng sông để có được số liệu rửa mặn, số 5% được tạm tính để chạy giả lập mô hình.
+	Sau khi tính toán xong lưu lượng nước cần xả hoặc giữ lại thì ta lấy lưu lượng nước đó chia cho thời gian đáp ứng thay đổi sẽ tính ra diện tích cửa đập cần mở, từ đó tiếp tục chia cho số cửa đập muốn mở và chia cho tổng chiều rộng các đập muốn mở sẽ ra được cao độ cần mở.
+	Sau khi đã có cao độ cần mở thì hệ thống sẽ ra lệch cho servo nâng hoặc hạ đập theo thông số yêu cầu.
-	Trong điều kiện mưa lũ, số liệu MT đạt mức quá cao, gần chạm đỉnh lũ MTH thì hệ thống sẽ gởi cảnh báo lũ cho người điều hành đập dâng ra quyết định can thiệp hay không.
4.	Vận hành thủ công:
Trong điều kiện thời tiết cực đoan, thiên tai, hoặc người điều hành muốn thực hiện các tác vụ để xử lý tức thời vấn đề, người điều hành có thể thực hiện can thiệp trực tiếp bằng cách chuyển qua chế độ vận hành thủ công, qua đó ra lệnh trực tiếp cho hệ thống như sau:
-	Thiết lập cao độ của từng cửa xả từ 0 đến 100
-	Thiết lập cao độ của cầu cá tự động theo chiều cao mực nước hoặc theo cao độ tự chọn từ 0 đến 100
-	Thiết lập cảnh báo hoặc chuyển sang chế độ tự động khi mực nước tại đập dâng hoặc hạ nguồn hoặc thượng nguồn hoặc độ mặn đến điều kiện cần phải chuyển sang chạy tự động hoặc báo động.
IV.	
V.	Ý tưởng mới
-	Các đập dâng hiện nay ở Việt Nam chưa có cầu cá, chưa có hệ thống vận hành theo số liệu đầu dò tại thượng lưu, hạ lưu mà chỉ điều tiết độ cao mực nước hiện tại ở đập dâng.
-	Chúng em chưa tìm thấy có đề tài nào trùng lặp ở Việt Nam nên có thể khẳng định tính mới của dự án.
-	Đặc biệt, đây là dự án vận hành hoàn toàn tự động theo kịch bản chuẩn bị trước hoặc có thể chuyển qua chế độ điều khiển bằng tay.
VI.	Tính sáng tạo
-	Sản phẩm là một dự án IoT có thể hoạt động hoàn toàn tự động, kiểm soát được số liệu từ xa cũng như được báo cáo cập nhật liên tục, nó đáp ứng được sự biến động bất ngờ của thời tiết, chủ động đưa ra cảnh báo để vận hành sớm hơn khi thiên tai ập đến.
VII.	Khả năng áp dụng thực tiển
-	Sản phẩm của chúng em được dựng lên từ thực tế đập dâng sông Trà Khúc – Quảng Ngãi, mong muốn áp dụng vào dự án Đập dâng sông Trà Khúc.
-	Sản phẩm được mô phỏng để có thể tự động xả nước khi mực nước thượng nguồn vượt ngưỡng yêu cầu, tự động tích nước khi mực nước xuống qua số liệu liên tục được cập nhật tự động qua hệ thống.
-	Hạn chế môi trường hạ lưu không bị ngập mặn, không thay đổi môi trường sinh sống tự nhiên của các sinh vật sống trên sông.

