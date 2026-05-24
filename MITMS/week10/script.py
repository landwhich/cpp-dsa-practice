from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.firefox.options import Options
import os

profile_path = os.path.expanduser(
    "replace with your OS and web's profile path" \
    "eg: ~/Library/Application Support/Firefox/Profiles/default-release" \
    "for firefox on mac"
)

options = Options()
options.profile = profile_path
driver = webdriver.Firefox(options=options)

# Open carleton login
driver.get("https://ssoman.carleton.ca/ssomanager/c/SSB")

# Wait for username field
username_field = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.ID, "userNameInput"))
)
username_field.clear()
username_field.send_keys("youruser")

password_field = driver.find_element(By.ID, "passwordInput")
password_field.clear()
password_field.send_keys("yourpass")

login_button = driver.find_element(By.ID, "submitButton")
login_button.click()

# Wait for successful redirect to central
WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.CLASS_NAME, "pageheaderlinks2"))
)

print("Login successful!")
print("Firefox remains open.")

input("Press ENTER to quit...")

driver.quit()