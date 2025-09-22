# Robô Seguidor de Linha com Arduino Uno R3

Este projeto implementa um robô seguidor de linha utilizando **Arduino Uno R3**, um **shield L293D** para controle dos motores e uma placa com **5 sensores TCRT5000** para detecção da linha.

## 🛠 Componentes Utilizados

- **Arduino Uno R3**
- **Shield L293D (Adafruit Motor Shield ou compatível)**
- **2 Motores DC** (acionados pelo shield)
- **Placa com 5 sensores infravermelhos TCRT5000**
- **Fonte de alimentação compatível com motores DC** (pilhas ou bateria)

## ⚙️ Funcionamento

O robô detecta a linha no chão através dos 5 sensores IR.  
A lógica de decisão é baseada na soma dos sensores laterais:

- **Sensores A e B (esquerda)**  
- **Sensor C (centro)**  
- **Sensores D e E (direita)**

### Regras principais:
- Se a soma dos sensores **esquerdos** > **direitos** → vira à **esquerda**  
- Se a soma dos sensores **direitos** > **esquerdos** → vira à **direita**  
- Se ambos forem iguais e o sensor **central** detectar a linha → segue em frente  
- Caso contrário → motores desligam  

## 🚀 Como Executar

1. Instale a biblioteca **Adafruit AFMotor** na IDE do Arduino:
   - `Sketch > Incluir Biblioteca > Gerenciar Bibliotecas...`  
   - Pesquise por **Adafruit Motor Shield** e instale.
2. Faça o upload do código para o **Arduino Uno R3**.
3. Conecte os sensores nos pinos analógicos **A0–A4**.
4. Conecte os motores DC nas saídas **M3** e **M4** do shield.
5. Alimente o circuito com bateria/fonte compatível.
6. Posicione o robô sobre uma linha preta em fundo branco (ou vice-versa).

## 🔧 Possíveis Melhorias

- Ajuste da velocidade dos motores (`setSpeed`) para melhorar a curva.  
- Calibração dos sensores para diferentes tipos de pista.  
- Implementar **PID control** para suavizar o movimento.  
- Uso de PWM para curvas mais precisas.

## 📄 Licença

Este projeto é de uso livre para fins acadêmicos e de aprendizado.

## Modelo utilizado


![foto-robo-segue-linha](https://github.com/user-attachments/assets/b4223a66-78cd-4d17-9a51-ef00bcf19a61)

![video-robo-segue-linha]https://github.com/user-attachments/assets/44d5db87-4987-4191-abf5-56bbc89b8a25)
