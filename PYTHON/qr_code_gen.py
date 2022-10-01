import pyqrcode
import png
from argparse import ArgumentParser
import validators
import os

# Constructing an Argument Parser
ap = ArgumentParser()
ap.add_argument(
    "-l", "--link", required=True, help="Link that is to be generated into QR Code"
)
ap.add_argument(
    "-p",
    "--path",
    default=os.getcwd(),
    help="Path where the QR Code files are to be saved",
)
args = vars(ap.parse_args())

if validators.url(args["link"]):
    # Generating QR code
    url = pyqrcode.create(args["link"])

    try:
        os.chdir(args["path"])

        # Creating svg and png files for the same in the same directory
        url.svg("qr_code.svg", scale=8)
        url.png("qr_code.png", scale=6)
        print("QR Code generated and saved.")

    except:
        print(
            "Something's wrong with specified directory.",
            "\nRetry with the correct path.",
        )

else:
    print("Invalid link provided.")
