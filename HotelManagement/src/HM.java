import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.SystemColor;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JList;
import javax.swing.AbstractListModel;
import javax.swing.JTextArea;
import javax.swing.JScrollBar;
import javax.swing.border.LineBorder;

public class HM {

	private JFrame frame;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					HM window = new HM();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public HM() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBackground(Color.WHITE);
		frame.setForeground(Color.WHITE);
		frame.getContentPane().setFont(new Font("Tahoma", Font.BOLD, 17));
		frame.setBounds(100, 100, 1510, 761);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Hotel management Tool");
		lblNewLabel.setBounds(554, 18, 453, 49);
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 40));
		lblNewLabel.setForeground(Color.BLACK);
		lblNewLabel.setBackground(SystemColor.text);
		frame.getContentPane().add(lblNewLabel);
		
		JButton btnNewButton = new JButton("R100");
		btnNewButton.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton.setBackground(Color.GREEN);
		btnNewButton.setBounds(72, 108, 125, 64);
		frame.getContentPane().add(btnNewButton);
		
		JLabel lblNewLabel_1 = new JLabel("NAME");
		lblNewLabel_1.setFont(new Font("Tahoma", Font.PLAIN, 23));
		lblNewLabel_1.setBounds(734, 211, 94, 52);
		frame.getContentPane().add(lblNewLabel_1);
		
		JLabel lblNewLabel_1_1 = new JLabel("DAYS");
		lblNewLabel_1_1.setFont(new Font("Tahoma", Font.PLAIN, 23));
		lblNewLabel_1_1.setBounds(734, 298, 94, 52);
		frame.getContentPane().add(lblNewLabel_1_1);
		
		JLabel lblNewLabel_1_1_1 = new JLabel("Date to book from");
		lblNewLabel_1_1_1.setFont(new Font("Tahoma", Font.PLAIN, 23));
		lblNewLabel_1_1_1.setBounds(734, 369, 214, 57);
		frame.getContentPane().add(lblNewLabel_1_1_1);
		
		JButton btnNewButton_3_2_1 = new JButton("Pay");
		btnNewButton_3_2_1.setBackground(Color.GREEN);
		btnNewButton_3_2_1.setForeground(Color.BLACK);
		btnNewButton_3_2_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
		btnNewButton_3_2_1.setBounds(734, 625, 125, 64);
		frame.getContentPane().add(btnNewButton_3_2_1);
		
		JTextArea textArea = new JTextArea();
		textArea.setFont(new Font("Monospaced", Font.PLAIN, 18));
		textArea.setBounds(838, 223, 527, 34);
		frame.getContentPane().add(textArea);
		
		JTextArea txtrSelectRoomTo = new JTextArea();
		txtrSelectRoomTo.setFont(new Font("Monospaced", Font.PLAIN, 17));
		txtrSelectRoomTo.setText("Green are the one avilabel, Red are occupied, blue are the ones you have chosen");
		txtrSelectRoomTo.setBounds(705, 108, 727, 64);
		frame.getContentPane().add(txtrSelectRoomTo);
		
		JButton btnNewButton_3_2_1_1 = new JButton("Refund");
		btnNewButton_3_2_1_1.setForeground(Color.WHITE);
		btnNewButton_3_2_1_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
		btnNewButton_3_2_1_1.setBackground(Color.RED);
		btnNewButton_3_2_1_1.setBounds(1307, 625, 125, 64);
		frame.getContentPane().add(btnNewButton_3_2_1_1);
		
		JButton btnNewButton_3_6 = new JButton("Login");
		btnNewButton_3_6.setFont(new Font("Tahoma", Font.PLAIN, 17));
		btnNewButton_3_6.setForeground(Color.BLACK);
		btnNewButton_3_6.setBounds(1329, 22, 125, 64);
		frame.getContentPane().add(btnNewButton_3_6);
		
		JTextArea txtrNill = new JTextArea();
		txtrNill.setText("Nill");
		txtrNill.setFont(new Font("Monospaced", Font.PLAIN, 17));
		txtrNill.setBounds(734, 508, 727, 64);
		frame.getContentPane().add(txtrNill);
		
		JLabel lblNewLabel_1_1_1_1 = new JLabel("Bill Info");
		lblNewLabel_1_1_1_1.setFont(new Font("Tahoma", Font.PLAIN, 23));
		lblNewLabel_1_1_1_1.setBounds(1041, 448, 214, 57);
		frame.getContentPane().add(lblNewLabel_1_1_1_1);
		
		JButton btnNewButton_3_6_1 = new JButton("Filter");
		btnNewButton_3_6_1.setBackground(Color.LIGHT_GRAY);
		btnNewButton_3_6_1.setForeground(Color.BLACK);
		btnNewButton_3_6_1.setFont(new Font("Tahoma", Font.PLAIN, 11));
		btnNewButton_3_6_1.setBounds(1229, 22, 65, 64);
		frame.getContentPane().add(btnNewButton_3_6_1);
		
		JButton btnR = new JButton("R101");
		btnR.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnR.setBackground(Color.GREEN);
		btnR.setBounds(222, 108, 125, 64);
		frame.getContentPane().add(btnR);
		
		JButton btnNewButton_1_6 = new JButton("R102");
		btnNewButton_1_6.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_6.setBackground(Color.GREEN);
		btnNewButton_1_6.setBounds(367, 108, 125, 64);
		frame.getContentPane().add(btnNewButton_1_6);
		
		JButton btnNewButton_1_7 = new JButton("R103\r\n");
		btnNewButton_1_7.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_7.setBackground(Color.GREEN);
		btnNewButton_1_7.setBounds(516, 108, 125, 64);
		frame.getContentPane().add(btnNewButton_1_7);
		
		JButton btnR_1 = new JButton("R200");
		btnR_1.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnR_1.setBackground(Color.GREEN);
		btnR_1.setBounds(72, 197, 125, 64);
		frame.getContentPane().add(btnR_1);
		
		JButton btnNewButton_1_1 = new JButton("R201");
		btnNewButton_1_1.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_1.setBackground(Color.GREEN);
		btnNewButton_1_1.setBounds(222, 197, 125, 64);
		frame.getContentPane().add(btnNewButton_1_1);
		
		JButton btnNewButton_1_6_1 = new JButton("R202");
		btnNewButton_1_6_1.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_6_1.setBackground(Color.GREEN);
		btnNewButton_1_6_1.setBounds(367, 197, 125, 64);
		frame.getContentPane().add(btnNewButton_1_6_1);
		
		JButton btnNewButton_1_7_1 = new JButton("R203\r\n");
		btnNewButton_1_7_1.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_7_1.setBackground(Color.GREEN);
		btnNewButton_1_7_1.setBounds(516, 197, 125, 64);
		frame.getContentPane().add(btnNewButton_1_7_1);
		
		JButton btnR_2 = new JButton("R300");
		btnR_2.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnR_2.setBackground(Color.GREEN);
		btnR_2.setBounds(72, 286, 125, 64);
		frame.getContentPane().add(btnR_2);
		
		JButton btnNewButton_1_2 = new JButton("R301");
		btnNewButton_1_2.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_2.setBackground(Color.GREEN);
		btnNewButton_1_2.setBounds(222, 286, 125, 64);
		frame.getContentPane().add(btnNewButton_1_2);
		
		JButton btnNewButton_1_6_2 = new JButton("R302");
		btnNewButton_1_6_2.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_6_2.setBackground(Color.GREEN);
		btnNewButton_1_6_2.setBounds(367, 286, 125, 64);
		frame.getContentPane().add(btnNewButton_1_6_2);
		
		JButton btnNewButton_1_7_2 = new JButton("R303");
		btnNewButton_1_7_2.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_7_2.setBackground(Color.GREEN);
		btnNewButton_1_7_2.setBounds(516, 286, 125, 64);
		frame.getContentPane().add(btnNewButton_1_7_2);
		
		JButton btnR_3 = new JButton("R400");
		btnR_3.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnR_3.setBackground(Color.GREEN);
		btnR_3.setBounds(72, 380, 125, 64);
		frame.getContentPane().add(btnR_3);
		
		JButton btnNewButton_1_3 = new JButton("R401");
		btnNewButton_1_3.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_3.setBackground(Color.GREEN);
		btnNewButton_1_3.setBounds(222, 380, 125, 64);
		frame.getContentPane().add(btnNewButton_1_3);
		
		JButton btnNewButton_1_6_3 = new JButton("R402\r\n");
		btnNewButton_1_6_3.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_6_3.setBackground(Color.GREEN);
		btnNewButton_1_6_3.setBounds(367, 380, 125, 64);
		frame.getContentPane().add(btnNewButton_1_6_3);
		
		JButton btnNewButton_1_7_3 = new JButton("R403");
		btnNewButton_1_7_3.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_7_3.setBackground(Color.GREEN);
		btnNewButton_1_7_3.setBounds(516, 380, 125, 64);
		frame.getContentPane().add(btnNewButton_1_7_3);
		
		JButton btnR_4 = new JButton("R500");
		btnR_4.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnR_4.setBackground(Color.GREEN);
		btnR_4.setBounds(72, 471, 125, 64);
		frame.getContentPane().add(btnR_4);
		
		JButton btnNewButton_1_4 = new JButton("R501\r\n");
		btnNewButton_1_4.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_4.setBackground(Color.GREEN);
		btnNewButton_1_4.setBounds(222, 471, 125, 64);
		frame.getContentPane().add(btnNewButton_1_4);
		
		JButton btnNewButton_1_6_4 = new JButton("R502");
		btnNewButton_1_6_4.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_6_4.setBackground(Color.GREEN);
		btnNewButton_1_6_4.setBounds(367, 471, 125, 64);
		frame.getContentPane().add(btnNewButton_1_6_4);
		
		JButton btnNewButton_1_7_4 = new JButton("R503");
		btnNewButton_1_7_4.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_7_4.setBackground(Color.GREEN);
		btnNewButton_1_7_4.setBounds(516, 471, 125, 64);
		frame.getContentPane().add(btnNewButton_1_7_4);
		
		JButton btnR_5 = new JButton("R600\r\n");
		btnR_5.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnR_5.setBackground(Color.GREEN);
		btnR_5.setBounds(72, 566, 125, 64);
		frame.getContentPane().add(btnR_5);
		
		JButton btnNewButton_1_5 = new JButton("R601");
		btnNewButton_1_5.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_5.setBackground(Color.GREEN);
		btnNewButton_1_5.setBounds(222, 566, 125, 64);
		frame.getContentPane().add(btnNewButton_1_5);
		
		JButton btnNewButton_1_6_5 = new JButton("R602");
		btnNewButton_1_6_5.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_6_5.setBackground(Color.GREEN);
		btnNewButton_1_6_5.setBounds(367, 566, 125, 64);
		frame.getContentPane().add(btnNewButton_1_6_5);
		
		JButton btnNewButton_1_7_5 = new JButton("R603");
		btnNewButton_1_7_5.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton_1_7_5.setBackground(Color.GREEN);
		btnNewButton_1_7_5.setBounds(516, 566, 125, 64);
		frame.getContentPane().add(btnNewButton_1_7_5);
		
		JScrollBar scrollBar = new JScrollBar();
		scrollBar.setBounds(1437, 108, 17, 64);
		frame.getContentPane().add(scrollBar);
		
		JList list_1 = new JList();
		list_1.setModel(new AbstractListModel() {
			String[] values = new String[] {"1/ 11/ 23", "2/ 11/ 23", "3/ 11/ 23"};
			public int getSize() {
				return values.length;
			}
			public Object getElementAt(int index) {
				return values[index];
			}
		});
		list_1.setFont(new Font("Tahoma", Font.PLAIN, 15));
		list_1.setBorder(new LineBorder(new Color(0, 0, 0)));
		list_1.setBounds(930, 379, 77, 65);
		frame.getContentPane().add(list_1);
		
		JTextArea textArea_1 = new JTextArea();
		textArea_1.setFont(new Font("Monospaced", Font.PLAIN, 18));
		textArea_1.setBounds(841, 312, 77, 34);
		frame.getContentPane().add(textArea_1);
		
		JScrollBar scrollBar_1 = new JScrollBar();
		scrollBar_1.setBounds(1469, 508, 17, 64);
		frame.getContentPane().add(scrollBar_1);
	}
}
