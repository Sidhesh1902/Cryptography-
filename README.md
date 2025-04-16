# Cryptography-
13 Cryptographic Encryption programs in C language

1. **Caesar Cipher**:  
   Shifts each letter in the plaintext by a fixed number of positions in the alphabet.  
   Simple and easy to break due to limited key space.

2. **Atbash Cipher**:  
   Substitutes each letter with its mirror in the alphabet (A ↔ Z, B ↔ Y, etc.).  
   A monoalphabetic cipher with only one possible key.

3. **August Cipher**:  
   Likely a mistaken name; often confused with **Caesar** or **Vigenère**. Let me know if you meant something specific.

4. **Affine Cipher**:  
   Applies a mathematical function (ax + b) mod 26 to encrypt each letter.  
   Requires both multiplicative and additive keys.

5. **Vigenère Cipher**:  
   Uses a keyword to shift each letter differently, repeating the keyword as needed.  
   Stronger than Caesar due to polyalphabetic substitution.

6. **Gronsfeld Cipher**:  
   Variant of Vigenère using digits (0–9) instead of letters as keys.  
   Commonly used with numerical keypads.

7. **Beaufort Cipher**:  
   Similar to Vigenère but with a reversed encryption formula.  
   Decryption and encryption use the same process.

8. **Autokey (Running Key) Cipher**:  
   Extends the Vigenère cipher by using plaintext itself as the key after an initial keyword.  
   Reduces repetition, making it harder to crack.

9. **N-gram Operations**:  
   Groups letters into fixed-length sequences (e.g., digrams, trigrams).  
   Often used in frequency analysis and cryptanalysis rather than encryption.

10. **Hill Cipher**:  
   Uses linear algebra and matrix multiplication to encrypt blocks of letters.  
   Requires an invertible key matrix for decryption.

11. **Rail Fence Cipher**:  
   A transposition cipher that writes the message in a zigzag pattern across multiple "rails".  
   Then reads the message line by line to form the ciphertext.

12. **Route Cipher**:  
   Writes plaintext in a grid and reads it off in a specific route (e.g., spiral, zigzag).  
   A form of transposition cipher.

13. **Myszkowski Cipher**:  
   A transposition cipher using a keyword with repeated letters to define columnar order.  
   Handles repeated letters in the key more systematically than standard columnar transposition.


